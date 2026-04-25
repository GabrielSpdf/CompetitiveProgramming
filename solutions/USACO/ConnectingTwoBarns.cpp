// TODO

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 2e9 + 7;

struct DSU{
    vector<int> p, sz;

    DSU(int n){
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        dsu.unite(a, b);
    }

    vector<vector<int>> comps(n);
    for(int i=0; i<n; i++){
        int root = dsu.find(i);
        comps[root].push_back(i);
    }

    if(dsu.find(0) == dsu.find(n-1)){
        cout << 0 << "\n";
        return;
    }

    vector<int> dist1(n, INF), distN(n, INF);
    for(int i=1; i<n; i++){
        auto it = lower_bound(comps[i].begin(), comps[i].end(), 0);
        int custo = (*it)*(*it);

        dist1[i] = min(dist1[i], custo);
    }

    for(int i=0; i<n-1; i++){
        auto it = lower_bound(comps[i].begin(), comps[i].end(), n-1);
        int custo = (*it-(n-1))*(*it-(n-1));

        distN[i] = min(dist1[i], custo);
    }
}

signed main(){
	// setIO("problemname");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; while(t--)
        solve();

    return 0;
}
