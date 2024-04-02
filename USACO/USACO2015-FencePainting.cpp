//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d, maxval, minval, cont=0;
    cin >> a >> b >> c >> d;
    maxval = max((max(a,b)),max(c,d));
    minval = min((min(a,b)),min(c,d));

    vector<bool> v(maxval, false);
    for(int i=a; i<b; i++){
        v[i]=true; cont++;
    }
    for(int j=c; j<d; j++){
        if(v[j]==false) cont++; 
        v[j]=true;
    }

    cout << cont << endl;

    return 0;
}