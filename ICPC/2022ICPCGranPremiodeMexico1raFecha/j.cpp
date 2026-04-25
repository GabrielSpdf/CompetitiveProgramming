#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

vector<vector<tuple<int, int, int>>> res;
vector<int> dist;
vector<int> itr;
int n, m, sz;

bool bfs(int src, int des){ // source / destiny
    queue<int> q;
    q.push(src);

    dist.assign(sz, -1);
    dist[src] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<(int)res[cur].size(); i++){
            auto nxt = get<0>(res[cur][i]);
            auto d = get<1>(res[cur][i]);

            if(dist[nxt]==-1 && d>0){
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }

    return dist[des]!=-1;
}

int dfs(int cur, int des, int pushed){
    if(cur == des) return pushed;

    for(int &i=itr[cur]; i<(int)res[cur].size(); i++){
        auto nxt = get<0>(res[cur][i]);
        auto d = get<1>(res[cur][i]);

        if(dist[nxt]==dist[cur]+1 && d>0){
            int f = dfs(nxt, des, min(d, pushed));
            if(f>0){
                get<1>(res[cur][i]) -= f;
                int who_am_i = get<0>(res[cur][i]);
                int where_is_it = get<2>(res[cur][i]);
                get<1>(res[who_am_i][where_is_it]) += f;
                return f;
            }
        }
    }
    return 0;
}

void maximum_flow(int src, int des){
    int total = 0;
    while(bfs(src, des)){ // layered graph
        itr.assign(sz, 0);
        while(true){
            int f = dfs(src, des, INF);
            if(f==0) break;
            total += f;
        }
    }
}

void solve(){
    cin >> n >> m;
    sz = n+m+2; // vertex S + n(0idx) + m(0idx) + vertex T

    res = vector<vector<tuple<int, int, int>>>(sz);
    dist = vector<int>(sz, -1);
    itr = vector<int>(sz, 0);

    for(int i=0; i<n; i++){
        int qtd; cin >> qtd;

        // add S vertex
        res[0].push_back({i+1, 1, res[i+1].size()});
        res[i+1].push_back({0, 0, res[0].size()-1});

        for(int j=0; j<qtd; j++){
            int emp; cin >> emp;
            emp = emp + n; // 0-idx

            res[i+1].push_back({emp, 1, res[emp].size()});
            res[emp].push_back({i+1, 0, res[i+1].size()-1});
        }
    }

    // add T vertex
    for(int i=0; i<m; i++){
        res[i+n+1].push_back({n+m+1, 1, res[n+m+1].size()});
        res[n+m+1].push_back({i+n+1, 0, res[i+n+1].size()-1});
    }

    int ans=0;
    maximum_flow(0, n+m+1);

    for(auto [nxt, d, idx] : res[n+m+1]){
        ans+=d;
    }

    cout << m-ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}