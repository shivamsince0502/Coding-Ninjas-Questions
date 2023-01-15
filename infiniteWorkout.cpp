#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(int n, int m) {
  ll ans = 1;
  for(int i = 1; i <= n+m; i++) 
    ans *= i;
  for(int i = 1; i <= n; i++) 
    ans /= i;
  for(int j = 1; j <= m; j++)
    ans /= j;
  return ans;
}

int main() {
  int t;cin>>t;
  while(t--) {
    int n, m;
    cin>>n>>m;
    cout<<solve(n, m)<<endl;
  }
}
