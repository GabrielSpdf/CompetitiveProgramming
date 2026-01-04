#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

int qtt;
int mx;

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

        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;

        qtt--;
        mx = max(mx, sz[a]);

        return true;
    }

    int getSize(int v){
        return sz[find(p[v])];
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    qtt = n;
    mx = 1;

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;

        dsu.unite(a, b);

        cout << qtt << " " << mx << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
