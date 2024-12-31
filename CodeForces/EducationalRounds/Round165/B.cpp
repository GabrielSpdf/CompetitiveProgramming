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
		string s;
		cin >> s;
		vector<pair<ll, ll>> v;
		ll one=-1, cont=0, sum=0;

		for(ll i=0; i<(ll)s.size(); i++){
			if(s[i]=='1' && one==-1) one=(i+1);
			if(s[i]=='0' && one!=-1){
				v.push_back(make_pair(one+cont, i+1));
				cont++;
			}
		}

		for(ll i=0; i<(ll)v.size(); i++){
			sum+=(v[i].second - v[i].first + 1);
		}

		cout << sum << "\n";

	}


    return 0;
}
