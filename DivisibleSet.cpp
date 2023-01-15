#include<bits/stdc++.h>
int includedElements(int n, vector<int>& set) {
  int ans = n, k = set.size();
  for(int i = 1; i < (1<<k); i++) {
    bitset<20> bit = i;
    long long lcm = 1;
    int cnt = 0;
    for(int j = 0; j < k; j++) {
      if(bit[j]) {
        cnt++;
        lcm = (lcm * set[j]) / __gcd(lcm , (long long)set[j]);
        if(lcm > n) break;
      }
    }
    if(lcm <= n){
      if(cnt & 1) 
        ans -= n/lcm;
      else 
        ans += n/lcm;
    }
  }
  return ans;
}
