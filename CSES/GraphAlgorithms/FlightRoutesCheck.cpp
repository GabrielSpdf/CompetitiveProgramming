#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

vector<vector<int>> listAdj;
vector<vector<int>> rev_listAdj;

vector<bool> visited;
int node_counter;

void dfs(int src, vector<vector<int>>& list){
    visited[src] = true;
    node_counter++;

    for(auto adj : list[src]){
        if(!visited[adj]) dfs(adj, list);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    rev_listAdj.assign(n, vector<int>());
    visited.assign(n, false);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        listAdj[a].push_back(b);
        rev_listAdj[b].push_back(a);
    }

    node_counter = 0;
    dfs(0, listAdj);
    if(node_counter != n){
        cout << "NO\n";
        cout << 1 << " ";
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cout << i+1 << "\n";
                return;
            }
        }
    }

    visited.assign(n, false);
    node_counter = 0;
    dfs(0, rev_listAdj);
    if(node_counter != n){
        cout << "NO\n";
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cout << i+1 << " ";
                break;
            }
        }
        cout << 1 << "\n";
        return;
    }

    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
