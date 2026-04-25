#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define FORU(stu, n) for(int u=(stu); u<(n); u++)
#define tvi(v) FORI((v).size()) cerr << (v)[i] << " "; cerr << "\n"
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI((v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI((v).size()) { FORJ((v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

int find_set(int v, vi &p) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v], p); }

void union_sets(int a, int b, vi &p) {
    a = find_set(a, p);
    b = find_set(b, p);
    if (a != b)
        p[b] = a;
}

void make_set(int v, vi &p) { p[v] = v; }

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vvi f(n), g(n);
    vi pf(n), pg(n);

	FORI(0, n){
        make_set(i, pf);
        make_set(i, pg);
    }
	FORI(0, m1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        f[u].pb(v);
        f[v].pb(u);
    }
	FORI(0, m2){
        int u, v;
        cin >> u >> v;
        u--; v--;
        union_sets(u, v, pg);
        g[u].pb(v);
        g[v].pb(u);
    }

    int ans = 0;
	FORU(0, n){ FORJ(0, f[u].size()){
			int v = f[u][j];
			if(find_set(u, pg) != find_set(v, pg)) ans++;
			else union_sets(u, v, pf);
        }
    }
	ans /= 2;

	FORU(0, n){ FORJ(0, g[u].size()){
            int v = g[u][j];
            if (find_set(u, pf) != find_set(v, pf)){ ans++; union_sets(u, v, pf); }
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
