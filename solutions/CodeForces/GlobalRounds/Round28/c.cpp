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
	string s;
	cin >> s;
	
	int ans=s.size();
	int cp1 = stoi(s, nullptr, 2);
	int cp2 = stoi(s, nullptr, 2);
	
	int max=0;
	int ps_ans;
	/* cout << "cp1: " << cp1 << "\n"; */
	/* cout << "cp2: " << cp2 << "\n"; */
	for(int i=lgg(cp2); i>=0; i--){
		int value = cp1 ^ (cp2>>i);
		/* cout << "value: " << value << "\n"; */
		if(value>max){
			ps_ans=i;
			max=value;
		}
	}
	/* cout << "ps_ans: " << ps_ans << "\n"; */

	cout << 1 << " " << s.size() << " " << 1 << " " << s.size()-ps_ans << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
