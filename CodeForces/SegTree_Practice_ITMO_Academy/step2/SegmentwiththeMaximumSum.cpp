// Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MIN = INT_MIN;
const double EPS = 1e-9;
const int MAX = 1e5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


struct mystruct{
	ll sum, suf, pref, seg;
	
};


int v[MAX];
vector<mystruct> seg(4*MAX);


mystruct build(ll p, ll l, ll r){
	if(l == r){
		mystruct cur = {
			v[l],
			v[l],
			v[l],
			v[l]
		};

		return seg[p]=cur;
	}

	ll m=(l+r)/2;

	mystruct esq = build(2*p, l, m);
	mystruct dir = build(2*p+1, m+1, r);

	mystruct res = {
		esq.sum + dir.sum,
		max(dir.suf, dir.sum + esq.suf),
		max(esq.pref, esq.sum + dir.pref),
		max(esq.seg, max(dir.seg, esq.suf + dir.pref))
	};
		
	return seg[p]=res;
}

mystruct query(ll a, ll b, ll p, ll l, ll r){
	if(a>r || b<l){
		mystruct cur = {
			0,
			MIN,
			MIN,
			MIN
		};

		return cur;
	}

	if(a<=l && b>=r) return seg[p];

	ll m=(l+r)/2;

	mystruct esq = query(a, b, 2*p, l, m);
	mystruct dir = query(a, b, 2*p+1, m+1, r);

	mystruct res = {
		esq.sum + dir.sum,
		max(dir.suf, dir.sum + esq.suf),
		max(esq.pref, esq.sum + dir.pref),
		max(esq.seg, max(dir.seg, esq.suf + dir.pref))
	};

	return res;
}

mystruct update(ll index, ll val, ll p, ll l, ll r){
	if(index>r || index<l) return seg[p];

	if(l == r){
		mystruct cur = {
			val,
			val, 
			val,
			val
		};

		return seg[p]=cur;
	}

	ll m=(l+r)/2;

	mystruct esq = update(index, val, 2*p, l, m);
	mystruct dir = update(index, val, 2*p+1, m+1, r);

	mystruct res = {
		esq.sum + dir.sum,
		max(dir.suf, dir.sum + esq.suf),
		max(esq.pref, esq.sum + dir.pref),
		max(esq.seg, max(dir.seg, esq.suf + dir.pref))
	};

	return seg[p]=res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> v[i];

	build(1, 0, n-1);

	mystruct ans = query(0, n-1, 1, 0, n-1);

	if(ans.seg < 0) cout << 0 << "\n";
	else cout << ans.seg << "\n";

	while(m--){
		int i, v;
		cin >> i >> v;

		update(i, v, 1, 0, n-1);

		mystruct ans = query(0, n-1, 1, 0, n-1);
		
		if(ans.seg < 0) cout << 0 << "\n";
		else cout << ans.seg << "\n";
	}

    return 0;
}
