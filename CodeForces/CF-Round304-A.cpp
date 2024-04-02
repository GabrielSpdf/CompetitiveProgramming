//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int MAX = 1000;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, n, w, ans;
    cin >> k >> n >> w;

    vector<ll> v(MAX+1, 0);
    for(int i=1; i<=MAX; i++){
        v[i]=v[i-1]+(k*i);
    }

    n >= v[w]? ans=0 : ans=v[w]-n;
    cout << ans << "\n";

    return 0;
}