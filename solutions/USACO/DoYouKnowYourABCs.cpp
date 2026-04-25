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

    vector<int64_t> v(7); for(auto& c : v) cin >> c;
    sort(v.begin(), v.end());

    int64_t a, b, c;
    a = v[0]; b = v[1];
    c = v[(int64_t)v.size()-1]-a-b;
    cout << a << " " << b << " " << c << "\n"; 

    return 0;
}