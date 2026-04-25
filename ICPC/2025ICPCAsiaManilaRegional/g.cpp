#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, b;
    cin >> n >> b;
    n--;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());

    int ans = b;
    for(int i=0; i<n; i++){
        if(v[i]<=0){
            if(ans!=b) break;

            if(ans >= -v[i]){ // consigo comprar
                cout << ans+v[i] << "\n";
                return;
            }
            else{ // nao consigo comprar
                cout << -1 << "\n";
                return;
            }
        }
        else{ // acumulando
            ans += v[i];
        }
    }

    cout << ans << "\n";
}

signed main(){
    solve();

    return 0;
}