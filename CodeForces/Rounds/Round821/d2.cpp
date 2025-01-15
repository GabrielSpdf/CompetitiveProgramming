// Unsolved yet

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

#define int long long

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

int ans1(vi& v, int x, int y){
	int ans=0;
	if(v.size()%2!=0) ans=-1;
	else{
		if(v.size()==2){
			if(v[1]-v[0]==1){
				if(x<=2*y) ans=x;
				else ans=2*y;
			}
			else ans=y;
		}
		else{
			ans=((v.size()/2)*y);
		}
	}

	return ans;
} 

int ans2(vi& v, int x, int y){
	int ans=0;
	if(v.size()%2!=0) ans=-1;
	else{
		int idx;
		int sz = v.size();
		for(int i=0; i<v.size()-1; i++){
			idx=i+1;
			if(v[idx]-v[i]==1){
				ans+=x;
				sz-=2;
				i++;
			}
		}
		ans+=((sz/2)*y);
	}

	return ans;
} 

void solve(){
	int n, x, y;
	cin >> n >> x >> y;

	string a, b;
	cin >> a >> b;
	
	vi v;
	for(int i=0; i<n; i++){
		if(a[i]!=b[i]) v.push_back(i);
	}
	
	int ans;
	if(y<=x) ans = ans1(v, x, y);
	else ans = ans2(v, x, y);

	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
