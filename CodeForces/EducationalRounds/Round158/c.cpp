#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

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

int lg(int x){
	int ans=0;
	while(x>1){
		x/=2;
		ans++;
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vi v(n);
	for(auto &a: v) cin >> a;
	
	sort(v.begin(), v.end());

	int mx = v[v.size()-1];
	int mn = v[0];
	int ans=0;
	vi vo;
	
	int trick = (mn+mx)/2; 
	while(mx!=mn){
		ans++;
		/* trick = (mn+mx)/2; */
		if(trick%2 - mn%2 !=0) trick++;
		/* if(mn%2!=0) trick=1; */
		/* else trick=0; */
		mn = (mn+trick)/2;
		mx = (mx+trick)/2;
		vo.push_back(trick);
	}

	cout << ans << "\n";
	if(vo.size()>0 && vo.size()<=n){
		for(int i=0; i<vo.size(); i++) cout << vo[i] << " ";
		cout << "\n";
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
