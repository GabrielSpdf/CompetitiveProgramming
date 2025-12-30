#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

int flood_fill(vector<vector<char>>& mtx, int i, int j, vector<vector<bool>>& visited){
    if(mtx.size()==0 || i<0 || j<0 || i>=mtx.size() || j>=mtx[0].size() || mtx[i][j]!='.' || visited[i][j]==1){
        return 0;
    }

    visited[i][j] = 1;

    flood_fill(mtx, i+1, j, visited);
    flood_fill(mtx, i-1, j, visited);
    flood_fill(mtx, i, j+1, visited);
    flood_fill(mtx, i, j-1, visited);

    return 1;
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    vector<vector<char>> mtx(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mtx[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans += flood_fill(mtx, i, j, visited);
        }
    }

    cout << ans << "\n";
}

signed main(){
    solve();

    return 0;
}
