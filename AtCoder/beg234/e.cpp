#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	ll n;
	cin >> n;

	set<ll> sll;
	
	for(int i=1; i<=18; i++){ // tamanho da string
		for(int j=1; j<=9; j++){ // primeiro numero da string
			for(int k=-9; k<=9; k++){ // PA dos numeros
				string s = "";
				s += to_string(j);

				for(int l=1; l<i; l++){
					// **
					if((s[s.size()-1]-0x30+k)>9 || (s[s.size()-1]-0x30+k)<0) break;
					else s += to_string(s[s.size()-1]-0x30+k);

				}
				// **
				if(s.size() == i) sll.insert(stoll(s));
			}
		}
	}

	// **
	cout << *sll.lower_bound(n) << "\n";
	
	/* cout << "sll.size(): " << sll.size() << "\n"; */
	/* cout << "sll: "; */
	/* for(auto it=sll.begin(); it!=sll.end(); it++){ */
	/* 	cout << *it << " "; */
	/* } */
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	/* int t; */
	/* cin >> t; */
	/* while(t--){ */
		solve();
	/* } */

    return 0;
}
