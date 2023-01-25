#include<bits/stdc++.h>
using namespace std;

int visited [51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool ispossible(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || (i >= n) || j >= m)
    {
        return false;
    }
    return true;
}

bool dfs(string board[], int x, int y, int fromX, int fromy, char needColor, int n, int m) {
    bool ans = false;
    if(!ispossible(x, y, n, m)) return ans;
    if(board[x][y] != needColor) return ans;
    if(visited[x][y]) return true;
    visited[x][y] = 1;
    for(int f = 0; f < 4; f++) {
        int nx = x + dx[f];
        int ny = y + dy[f];
        if(nx == fromX && ny = fromy) continue;
        ans |= dfs(board, nx, ny, x, y, needColor, n, m);
    }
    return ans;
}

int solve(string board[], int n, int  m) {
    int i, j;
    memset(visited, 0, sizeof(visited));
    bool ans = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j])
                ans |= dfs(board, i, j, -1, -1,board[i][j], n, m);
        }
    }
    return ans;
}


int main(){
    int n, m;
    cin>>n>>m;
    string board[n];
    for(int i = 0; i < n; i++) {
        cin>>board[i];
    }
    bool ans = solve(board, n, m);
    if(ans) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
