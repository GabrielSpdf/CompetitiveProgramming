//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n;
		bool ver=false;
		string s, st, s0, s1;

		cin >> n >> s;
		st = s;
		reverse(st.begin(), st.end());

		if(s <= st) ver=true;

		if(ver==true && n%2==0) cout << s << "\n";
		else if(ver==true && n%2!=0) cout << s+st << "\n";
		else if(ver==false && n%2==0) cout << st+s << "\n";
		else if(ver==false && n%2!=0) cout << s << "\n";
	}



    return 0;
}
