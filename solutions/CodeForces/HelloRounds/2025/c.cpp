// Unsolved

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

int lgg(int x) {
    int ans = 0;
    while (x > 0) {
        ans++;
        x = x >> 1;
    }
    return ans-1;
}

void solve(){
	int l, r;
	cin >> l >> r;
	
	bool dif=false;
	
	int c=0;
	for(int i=lgg(r); i>=0; i--){
		int bitr = ((r>>i)&1); // r MAIOR
		int bitl = ((l>>i)&1); // l MENOR
		if(dif==false){
			if(bitr != bitl) dif=true;
			c += l<<i;
		}
		else{
			c += (!l)<<i;
		}
	}

	cout << c << " " << l << " " << r << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
