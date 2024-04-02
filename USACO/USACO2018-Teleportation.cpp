//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, c, d, aux, minval, maxval, ans1, ans2, ans;
    cin >> a >> b >> c >> d;

    if(a>b){
        aux=a;
        a=b;
        b=aux;
    }

    minval=min(c,d);
    maxval=max(c,d);

    ans1 = abs(b-a);
    ans2 = abs(a-minval)+abs(b-maxval);

    if(a==b){ cout << 0 << "\n"; return 0; }
    ans1 <= ans2? ans=ans1 : ans=ans2;

    cout << ans << "\n";

    return 0;
}