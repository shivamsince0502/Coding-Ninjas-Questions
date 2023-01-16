import java.util.*;

public
class Solution
{
    static ArrayList<Pair<Integer, Integer>> twoSum(ArrayList<Integer> a, int t, int n)
    {
        ArrayList<Pair<Integer, Integer>> op = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++)
        {
            if (map.containsKey(a.get(i)))
            {
                map.put(a.get(i), map.get(a.get(i)) + 1);
            }
            else
            {
                map.put(a.get(i), 1);
            }
        }
        boolean ap = false;
        for (int i = 0; i < n; i++)
        {
            int target = t - a.get(i);
            int num = a.get(i);
            if(target == num) {
                if(map.get(num) > 1) {
                    op.add(new Pair(num, num));
                    map.put(num, map.get(num)-2);
                }
            }
            else if (map.containsKey(target) && map.get(num) > 0 && map.get(target) > 0)
            {
                ap = true;
                op.add(new Pair(num, target));
                map.put(target, map.get(target) - 1);
                map.put(num, map.get(num) - 1);
            }
        }
        if (op.size() == 0)
        {
            op.add(new Pair(-1, -1));
        }
        return op;
    }
}   
