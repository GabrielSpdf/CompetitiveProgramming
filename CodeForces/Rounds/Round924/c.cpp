#include <bits/stdc++.h>

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

vi calc(int alvo, bool ver){
	set<int> temp;
	
	for(int i=1; i*i<=alvo; i++){
		if(alvo%i==0){
			if(i%2==0){
				temp.insert(i);
			}
			if((alvo/i)%2==0){
				temp.insert(alvo/i);
			}
		}
	}
	
	vi v(temp.begin(), temp.end());

	for(int i=0; i<v.size(); i++){
		v[i] = (v[i]/2) + 1;
		/* cerr << v[i] << " "; */
	}

	return v;
}

void solve(){
	int n, x;
	cin >> n >> x;
	
	int ans=0;
	vi v1, v2;
	v1 = calc(n-x, false);
	/* cerr << "\n"; */
	v2 = calc(n-2+x, true);
	/* cerr << "\n"; */

	set<int> st;
	for(int i=0; i<v1.size(); i++) if(v1[i]>=x) st.insert(v1[i]);
	for(int i=0; i<v2.size(); i++) if(v2[i]>=x) st.insert(v2[i]);

	cout << st.size() << "\n";

	/* cout << ans << "\n"; */
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
