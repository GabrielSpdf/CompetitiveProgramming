#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

vector<vector<int>> listAdj;
vector<int> dist;
vector<int> path;

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    path.assign(n, -1);
    dist.assign(n, -1);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;

        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    // start 0 | end n
    dist[0] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto adj : listAdj[curr]){
            if(dist[adj] != -1) continue;
            path[adj] = curr;
            dist[adj] = dist[curr] + 1;
            q.push(adj);
        }
    }

    int ans = dist[n-1];
    if(ans == -1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << ans << "\n";
    int curr = n-1;
    int st = 0;
    vector<int> track;
    while(curr != st){
        track.push_back(curr+1);
        curr = path[curr];
    }
    track.push_back(1);

    reverse(track.begin(), track.end());
    for(auto &a : track){
        cout << a << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
