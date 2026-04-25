#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<bool> visited;
vector<vector<int>> adj;
vector<int> dist;

int exp(int base, int p){
    int res = 1;
    while(p){
        if(p & 1) res*=base;
        p /= 2;
        base *= base;
    }
    return res;
}

pair<int, int> bfs(int src){
    queue<int> q;
    q.push(src);
    int mx = -1;

    while(!q.empty()){
        int cur = q.front();
        visited[cur] = true;
        q.pop();
        mx = max(mx, cur);

        for(auto nxt : adj[cur]){
            if(visited[nxt]) continue;
            q.push(nxt);
        }
    }

    return {mx, src};
}

void solve(){
    int n, m; cin >> n >> m;

    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    dist = vector<int>(n);
    iota(dist.begin(), dist.end(), 1);

    vector<int> cand;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;

        if(a == n-1){
            cand.push_back(b);
            continue;
        }
        if(b == n-1){
            cand.push_back(a);
            continue;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mx = -1, who = -1;
    for(int i=0; i<cand.size(); i++){
        pair<int, int> res;
        res = bfs(cand[i]);

        if(res.first > mx){
            mx = res.first;
            who = res.second;
        }
    }

    visited.assign(n, false);
    bfs(who);

    for(int i=0; i<n; i++){
        if(visited[i]) cout << "B";
        else cout << "A";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}