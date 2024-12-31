#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	ll siz, dif;
	string s, t;
	cin >> s >> t;
	siz = max(s.size(), t.size());

	if(s==t) cout << "0\n";
	else{
		for(ll i=0; i<siz; i++){
			if(s[i]!=t[i] || i+1 > s.size() || i+1 > t.size()){ cout << i+1 << "\n"; break; }
		}
	}


    return 0;
}

