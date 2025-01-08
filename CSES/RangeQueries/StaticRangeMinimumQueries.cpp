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

const int MAX = 212345;
const long long LLINF = 4e18;

ll seg[4*MAX], v[MAX];

ll build(ll p, ll l, ll r){
	if(l==r) return seg[p]=v[l];

	ll m=(l+r)/2;

	return seg[p]=min(build(2*p, l, m), build(2*p+1, m+1, r));
}

ll query(ll a, ll b, ll p, ll l, ll r){
	if(a>r || b<l) return LLINF;

	if(a<=l && b>=r) return seg[p];

	ll m = (l+r)/2;

	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=0; i<n; i++) cin >> v[i];

	build(1, 0, n-1);

	for(int i=0; i<q; i++){
		ll q1, q2;
		cin >> q1 >> q2; 
		q1--; q2--;
		
		cout << query(q1, q2, 1, 0, n-1) << "\n";
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
