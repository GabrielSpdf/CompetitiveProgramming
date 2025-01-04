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
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vi aux(n);
	int mx=n, mn=1;
	bool hass=false, hasp=false;

	if(s.find('s')!=string::npos) hass=true;
	if(s.find('p')!=string::npos) hasp=true;
	
	string ans="YES";
	if(hass && hasp){
		int counts=0, countp=0;
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='p'){
				countp++;
			}
			if(s[i]=='s'){
				counts++;
			}
			/* if(s[i]=='.'){ */
			/* } */
		}
		if((counts>1 && countp>1) || (countp>1 && s[0]!='s') || (counts>1 && s[n-1]!='p') || (s[0]!='s' && s[n-1]!='p')) ans="NO";
	}
	cout << ans << "\n";
	// . . . s . p p 
	//		 1 2 3 4    
	// nao pode ter p s
	// se tiver p & s na string nao pode ter . circulando eles
	// s p . .
	// 1 2 3 4
	// . . . . s p
	//         2 1
	// . s p .
	// s . p . p . p .
	// 1 2 3 4 5 6 7 8
	// s s p 
	// 3 2 1
	// s p p 
	// 1 2 3
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
