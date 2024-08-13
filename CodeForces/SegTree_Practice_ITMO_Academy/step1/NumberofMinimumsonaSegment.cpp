// Accepted

#include <bits/stdc++.h>

using namespace std;

const long long LLINF = 4e18;
const int MAX = 1e5+103;

typedef long long ll;

ll v[MAX];
vector<pair<ll, ll>> seg(4*MAX);

pair<ll, ll> build(ll p, ll l, ll r){
	pair<ll, ll> par = make_pair(v[l], 1);
	if(l == r) return seg[p]=par;

	ll m=(l+r)/2;
	
	pair<ll, ll> esq = build(2*p, l, m), dir = build(2*p+1, m+1, r);

	if(esq.first == dir.first) return seg[p] = make_pair(esq.first, esq.second+dir.second);

	return seg[p]=min(esq, dir);
}


pair<ll, ll> query(ll a, ll b, ll p, ll l, ll r){
	if(a>r || b<l) return make_pair(LLINF, LLINF);

	if(a<=l && b>=r) return seg[p];

	ll m=(l+r)/2;

	pair<ll, ll> esq = query(a, b, 2*p, l, m), dir = query(a, b, 2*p+1, m+1, r);

	if(esq.first == dir.first) return make_pair(esq.first, esq.second+dir.second);

	return min(esq, dir);
}

pair<ll, ll> update(ll index, ll val, ll p, ll l, ll r){
	if(index>r || index<l) return seg[p];

	if(l == r) return seg[p]=make_pair(val, 1);

	ll m=(l+r)/2;

	pair<ll, ll> esq = update(index, val, 2*p, l, m), dir = update(index, val, 2*p+1, m+1, r);

	if(esq.first == dir.first) return seg[p] = make_pair(esq.first, esq.second+dir.second);

	return seg[p]=min(esq, dir);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<n; i++) cin >> v[i];

	build(1, 0, n-1);

	for(ll i=0; i<m; i++){
		ll op, a, b;
		cin >> op >> a >> b;
		
		if(op == 2){
			pair<ll, ll> ans = query(a, b-1, 1, 0, n-1);

			cout << ans.first << " " << ans.second << "\n";
		}
		if(op == 1) update(a, b, 1, 0, n-1);
	}	


    return 0;
}
