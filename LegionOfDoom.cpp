#include <bits/stdc++.h>
using namespace std;
#define int long long

void buildTree(int *arr, int *tree, int start, int end, int treeNode) {
  if (start == end) {
    tree[treeNode] = arr[start];
    return;
  }

  int mid = (start + end) / 2;

  buildTree(arr, tree, start, mid, 2 * treeNode);
  buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateSgmentTreeLazy(int *tree, int *lazy, int start, int end,
                          int treeNode, int left, int right, int incr) {
  if (start > end)
    return;

  if (lazy[treeNode] != 0) {
    tree[treeNode] += lazy[treeNode] * (end - start + 1);

    if (start != end) {
      lazy[2 * treeNode] += lazy[treeNode];
      lazy[2 * treeNode + 1] += lazy[treeNode];
    }

    lazy[treeNode] = 0;
  }

  if (start > right || end < left)
    return;

  if (start >= left && end <= right) {
    tree[treeNode] += (end - start + 1) * incr;

    if (start != end) {
      lazy[2 * treeNode] += incr;
      lazy[2 * treeNode + 1] += incr;
    }
    return;
  }

  int mid = (start + end) / 2;

  updateSgmentTreeLazy(tree, lazy, start, mid, 2 * treeNode, left, right, incr);
  updateSgmentTreeLazy(tree, lazy, mid + 1, end, 2 * treeNode + 1, left, right,
                       incr);

  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int *lazy, int start, int end, int treeNode, int left,
          int right) {
  if (start > right || end < left) {
    return 0;
  }

  if (lazy[treeNode] != 0) {
    tree[treeNode] += lazy[treeNode] * (end - start + 1);

    if (start != end) {
      lazy[2 * treeNode] += lazy[treeNode];
      lazy[2 * treeNode + 1] += lazy[treeNode];
    }

    lazy[treeNode] = 0;
  }

  if (start >= left && end <= right) {
    return tree[treeNode];
  }

  int mid = (start + end) / 2;

  int ans1 = query(tree, lazy, start, mid, 2 * treeNode, left, right);
  int ans2 = query(tree, lazy, mid + 1, end, 2 * treeNode + 1, left, right);

  return ans1 + ans2;
}

signed main() {

  // write your code here
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
      arr[i] = 0;

    int *tree = new int[4 * n]();
    int *lazy = new int[4 * n]();
    buildTree(arr, tree, 1, n, 1);

    int c;
    cin >> c;
    while (c--) {
      int a, left, right;
      cin >> a >> left >> right;
      if (a == 1) {
        cout << query(tree, lazy, 1, n, 1, left, right) << endl;
      } else if (a == 0) {
        int incr;
        cin >> incr;
        updateSgmentTreeLazy(tree, lazy, 1, n, 1, left, right, incr);
      }
    }
  }
  return 0;
}
