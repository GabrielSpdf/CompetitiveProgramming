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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


void solve(){
	int n, x, y;
	cin >> n >> x >> y; x--; y--;
		
	
	vi ans(n);
	if(n%2==0){
		for(int i=0; i<n; i++){
			if(i%2==0) ans[i]=0;
			else ans[i]=1;
		}
		
		int mn = min(x, y), mx = max(x, y);
		if(ans[mn]==ans[mx]) ans[mx]=2;
	}
	else{
		for(int i=0; i<n-1; i++){
			if(i%2==0) ans[i]=0;
			else ans[i]=1;
		}
		ans[n-1]=2;

		int mn = min(x, y), mx = max(x, y);
		if(ans[mn] == ans[mx]){
			if(ans[mx]==1) ans[mn]=2;
			else{
				int st=mn+1, value=0;
				ans[mn]=1;
				while(st!=mn){
					if(st==mx || st==(((mn-1)%n+n)%n)) ans[st]=2;
					else ans[st]=value;

					if(value==1) value=0;
					else value=1;

					st = (st+1)%n;
				}
			}
		}
	}
	

	for(int i=0; i<n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
