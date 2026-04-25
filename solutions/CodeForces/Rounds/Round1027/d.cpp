#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI(0, (v).size()) cerr << (v)[i] << " "; cerr << "\n";
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI(0, (v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI(0, (v).size()) { FORJ(0, (v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 
#define rall(v) (v).rbegin(), (v).rend() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

int calculate_rec(vii points){
    int x_mn=INT64_MAX, x_mx=INT64_MIN, y_mn=INT64_MAX, y_mx=INT64_MIN;
    for(auto [x, y] : points){
        if(x<x_mn) x_mn=x;
        if(y<y_mn) y_mn=y;
        if(x>x_mx) x_mx=x;
        if(y>y_mx) y_mx=y;
    }
    // cerr << "x_mn: " << x_mn << " | y_mn: " << y_mn << "\n";
    // cerr << "x_mx: " << x_mx << " | y_mx: " << y_mx << "\n";

    return ((x_mx-x_mn+1)*(y_mx-y_mn+1));
}

void solve(){
    int n;
    cin >> n;
    vii v(n);
    for(auto &[a, b]: v) cin >> a >> b;

    // TODO: Criar 2 vetores. Ordenar um em funcao de x e o outro em funcao de y. 
    // Testar remover a tupla do comeco e do final de cada um e, em seguida, pegar o menor resultado
    cout << calculate_rec(v) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
