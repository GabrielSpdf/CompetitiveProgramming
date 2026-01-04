#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;

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

        p[b] = a;
        sz[b] += sz[a];

        return true;
    }

    int getSize(int v){
        return sz[find(v)];
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while(q--){
        int tp, a, b;
        cin >> tp >> a >> b;
        if(tp == 0){
            dsu.unite(a, b);
        }
        else{
            cout << (dsu.find(a) == dsu.find(b)? 1 : 0) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
