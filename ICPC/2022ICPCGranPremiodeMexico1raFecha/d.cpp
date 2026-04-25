#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

typedef vector<vector<int>> mtx;
typedef vector<int> vi;

mtx adj;
vi v0;
int n, m, k;

mtx mtxMul(mtx& a, mtx& b){
    // nxn
    mtx ans(n, vi(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ans[i][j] = (ans[i][j] + ((a[i][k]*b[k][j])%MOD)) % MOD;
            }
        }
    }
    return ans;
}

mtx mtxExp(mtx& base, int p){
    mtx ans(n, vi(n, 0)); // identity mtx

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = (i==j);
        }
    }

    while(p){
        if(p & 1){
            ans = mtxMul(ans, base);
        }
        base = mtxMul(base, base);
        p>>=1;
    }
    return ans;
}

vi mtxViMul(mtx& base, vi& v){
    vi ans(n, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i] = (ans[i] + ((base[i][j]*v[j])%MOD))%MOD;
        }
    }
    return ans;
}

void solve(){
    cin >> n >> m >> k;

    adj = mtx(n, vi(n, 0)); // adj matrix

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    v0 = vector<int>(n, 0);
    v0[0] = 1;

    // adj^k * v0
    mtx base = adj;
    base = mtxExp(base, k);

    vi v;
    v = mtxViMul(base, v0);

    int ans=0;
    for(int i=0; i<n; i++){
        ans=((ans+v[i])%MOD);
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}