//Accepted

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

	int t;
	cin >> t;
	while(t--){
		ll n;
		string s;

		cin >> n;

		n = double(n);
		n = ((((((n*567)/9)+7492)*235)/47)-498);

		cout << (abs(n%100)-abs(n%10))/10 << "\n";

		/* cout << s[9] << "\n"; */
	}


    return 0;
}
