#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

vector<vector<int>> listAdj;
vector<int> colors;

bool bfs(int src){
    queue<int> q;
    q.push(src);
    colors[src] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto adj : listAdj[curr]){
            if(colors[adj] == colors[curr]){
                return false;
            }

            if(colors[adj] == -1){
                colors[adj] = 3 - colors[curr];
                q.push(adj);
            }
        }
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    colors.assign(n, -1);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        if(colors[i]==-1){
            bool verify = bfs(i);
            if(!verify){
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << colors[i] << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
