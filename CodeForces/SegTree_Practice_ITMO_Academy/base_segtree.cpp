#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const int MAX = 1e5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int seg[MAX], v[MAX];


ll build(ll p, ll l, ll r){
	if(l == r) return seg[p]=v[l];

	ll m=(l+r)/2;
		
	return seg[p]=min(build(2*p, l, m), build(2*p+1, m+1, r));
}

ll query(ll a, ll b, ll p, ll l, ll r){
	if(a>r || b<l) return LLINF;

	if(a<=l && b>=r) return seg[p];

	ll m=(l+r)/2;

	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

ll update(ll index, ll val, ll p, ll l, ll r){
	if(index>r || index<l) return seg[p];

	if(l == r) return seg[p]=val;

	ll m=(l+r)/2;

	return seg[p]=min(update(index, val, 2*p, l, m), update(index, val, 2*p+1, m+1, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
