#include <iostream>
#include <vector>

#define int long long

using namespace std;

vector<vector<int>> listAdj;
vector<bool> visited;

void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;

    for(auto u : listAdj[s]){
        dfs(u);
    }
}

signed main(){
    int n, m;
    cin >> n >> m;

    listAdj = vector<vector<int>>(n);
    visited = vector<bool>(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;
        listAdj[u].push_back(v);
        listAdj[v].push_back(u);
    }

    int ans = 0;
    vector<int> goTo;
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            goTo.push_back(i+1);
            ans++;
            dfs(i);
        }
    }

    cout << --ans << "\n";
    for(int i=1; i<goTo.size(); i++){
        cout << goTo[i-1] << " " << goTo[i] << "\n";
    }

    return 0;
}