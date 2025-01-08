#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int MAX=212345;

ll seg[4*MAX], v[MAX];

ll build(ll p, ll l, ll r){
	if(l==r) return seg[p]=v[l];

	ll m=(l+r)/2;

	return seg[p]=build(2*p, l, m)+build(2*p+1, m+1, r);
}

ll query(ll r1, ll r2, ll p, ll l, ll r){
	if(r2<l || r1>r) return 0;

	if(r2>=r && r1<=l) return seg[p];

	ll m=(l+r)/2;

	return query(r1, r2, 2*p, l, m)+query(r1, r2, 2*p+1, m+1, r);
}

ll update(ll idx, ll val, ll p, ll l, ll r){
	if(idx>r || idx<l) return seg[p];

	if(l==r) return seg[p]=val;

	ll m=(l+r)/2;

	return seg[p]=update(idx, val, 2*p, l, m)+update(idx, val, 2*p+1, m+1, r);
}

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=0; i<n; i++) cin >> v[i];

	build(1, 0, n-1);

	for(int i=0; i<q; i++){
		int q1, q2, q3; 
		cin >> q1 >> q2 >> q3;
		q2--; q3--;
	
		if(q1==2) cout << query(q2, q3, 1, 0, n-1) << "\n";
		if(q1==1) update(q2, q3+1, 1, 0, n-1);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
