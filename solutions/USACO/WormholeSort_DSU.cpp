#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct DSU{
    vector<int> p;
    vector<int> sz;

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
        if(sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }

    int getSize(int v){
        return sz[find(v)];
    }
};

vector<int> v;

bool check(DSU& dsu){
    int n = (int)v.size();
    for(int i=0; i<n; i++){
        if(dsu.find(i) != dsu.find(v[i])) return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    v.resize(n);
    for(auto &a: v){ cin >> a; a--;}

    DSU dsu(n);
    vector<tuple<int, int, int>> vt(m);
    for(int i=0; i<m; i++){
        int a, b, p;
        cin >> a >> b >> p; a--; b--;
        get<0>(vt[i]) = p;
        get<1>(vt[i]) = a;
        get<2>(vt[i]) = b;
    }
    sort(vt.rbegin(), vt.rend());

    for(int i=0; i<n; i++){
        if(v[i] != i) break;
        if(v[i] == i && i==n-1){
            cout << -1 << "\n";
            return;
        }
    }

    for(int i=0; i<m; i++){
        int fst = get<1>(vt[i]);
        int snd = get<2>(vt[i]);
        dsu.unite(fst, snd);

        if(check(dsu)){
            cout << get<0>(vt[i]) << "\n";
            return;
        }
    }
}

signed main(){
	setIO("wormsort");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
