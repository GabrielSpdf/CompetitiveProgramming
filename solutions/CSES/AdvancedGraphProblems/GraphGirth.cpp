#include <bits/stdc++.h>

#define int long long

using namespace std;

const int INF = 1e9;

typedef vector<int> vi;

vector<vector<int>> listAdj;
vector<int> dist;
vector<int> parent;
vector<int> cands;

int bfs(int i){
    fill(dist.begin(), dist.end(), -1);
    fill(parent.begin(), parent.end(), -1);

    queue<int> q;
    q.push(i);
    dist[i] = 0;

    int min_cycle = INF;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto adj : listAdj[curr]){
            if(adj == parent[curr]) continue;

            if(dist[adj]!=-1){
                min_cycle = min(min_cycle, dist[curr] + dist[adj] + 1);
            }
            else{
                dist[adj] = dist[curr] + 1;
                parent[adj] = curr;
                q.push(adj);
            }
        }
    }
    return min_cycle;
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    dist.resize(n);
    parent.resize(n);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    int ans = INF;
    for(int i=0; i<(int)dist.size(); i++){
        ans = min(ans, bfs(i));
    }

    cout << (ans < INF ? ans : -1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
