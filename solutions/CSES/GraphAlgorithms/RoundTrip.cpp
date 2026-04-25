include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

vector<vector<int>> listAdj;
vector<bool> visited;
vector<int> path;
int st = -1;

bool dfs(int src, int parent){
    visited[src] = true;

    for(auto adj : listAdj[src]){
        if(adj == parent) continue;

        path[adj] = src;
        if(visited[adj]){
            st = src;
            return true;
        }

        if(dfs(adj, src)){
            return true;
        }
    }

    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    visited.assign(n, false);
    path.assign(n, -1);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    bool check;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            check = dfs(i, -1);
            if(check) break;
        }
    }

    if(!check){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> track;
    track.push_back(st+1);
    int curr = path[st];

    while(curr != st){
        track.push_back(curr+1);
        curr = path[curr];
    }
    cout << track.size()+1 << "\n";
    for(auto &a : track){
        cout << a << " ";
    }
    cout << track[0];
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
