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

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    ll b0, b1, s0, s1, g0, g1, p0, p1, cbs=0, csg=0, cgp=0;
    cin >> b0 >> b1 >> s0 >> s1 >> g0 >> g1 >> p0 >> p1;

    cbs+=(s1-s0)+(g1-g0)+(p1-p0);
    csg+=(g1-g0)+(p1-p0);
    cgp+=(p1-p0);

    cout << cbs << "\n" << csg << "\n" << cgp << "\n";

    return 0;
}