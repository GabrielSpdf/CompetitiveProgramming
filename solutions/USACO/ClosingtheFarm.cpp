#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<int>> listAdj;
vector<bool> visited;
vector<bool> removed;
int nodes_count;

void dfs(int src){
    visited[src] = true;
    nodes_count++;

    for(auto adj : listAdj[src]){
        if(visited[adj] || removed[adj]) continue;
        dfs(adj);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    removed.assign(n, false);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;

        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        int q; cin >> q; q--;
        nodes_count = 0;

        visited.assign(n, false);

        for(int j=0; j<n; j++){
            if(removed[j]) continue;

            dfs(j);
            cout << ((nodes_count != n-i)? "NO" : "YES") << "\n";
            break;
        }
        removed[q] = true;
    }
}

signed main(){
	setIO("closing");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
