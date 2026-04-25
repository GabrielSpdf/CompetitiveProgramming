// thinking

#include <algorithm>
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

void pvi(vll v){
	cerr << "printing: ";
	for(int i=0; i<v.size(); i++) cerr << v[i] << " ";
	cerr << "\n";
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vll v(n);
	for(auto &a: v) cin >> a;

	sort(v.begin(), v.end());
	vll aux(n, 0);
	for(int i=1; i<n; i++){ aux[i]=i*(v[i]-v[i-1]); }

	vll pfs(n, 0);
	for(int i=1; i<n; i++) pfs[i]=pfs[i-1]+aux[i]; // qnt precisa no total
	
	pvi(aux); pvi(pfs);
	int last_pos;
	for(int i=0; i<n; i++){
		if(k>=pfs[i]){
			last_pos = i; // i==0 garantido
		}
	}
	
	ll ans;
	ll rmng=min(n-last_pos+1, 2LL);
	if(v.size()==1){ cout << v[0]+k << "\n"; return; }
	if(last_pos==0){ ans=*min_element(v.begin(), v.end())+k; cerr << "nem no primeiro\n"; } // nao bate nem no primeiro lvl
	else{
		if(upper_bound(pfs.begin(), pfs.end(), k)==pfs.end()){ // k ja chegou chegou/passou no ultimo lvl
			/* cerr << pfs[pfs.size()-1] << "\n"; */
			cerr << "chego/passou\n";
			ans = *max_element(v.begin(), v.end());
			rmng = min((k-pfs[pfs.size()-1]), 2LL);
		}
		else{ ans = v[last_pos]; cerr << "foi ate um lugar\n"; }
	}
	
	cerr << "ans: " << ans << "\n";
	cerr <<  "rmng: " << rmng << "\n";
	ans+=rmng;
	cout << (n*ans)-(n-1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
