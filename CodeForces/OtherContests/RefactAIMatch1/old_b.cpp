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
	int n;
	string s, r;

	cin >> n >> s >> r;
	
	int cases_0=0, cases_1=0;
	bool preIs0=false, posIs0=false, preIs1=false, posIs1=false;

	for(int i=0; i<(int)s.size()-1; i++){
		preIs0=false, posIs0=false, preIs1=false, posIs1=false;

		if((s[i]=='1'&&s[i+1]=='0') || (s[i]=='0'&&s[i+1]=='1')){
			if(i-1 >= 0){
				if(s[i-1]=='0') preIs1=true;
				else preIs0=true;
			}
			else{ preIs1=true; preIs0=true; }

			if(i+2 <= (int)s.size()-1){
				if(s[i+2]=='0') posIs1=true;
				else posIs0=true;
			}
			else{ posIs1=true; posIs0=true;}

			/* cout << "presis1: " << preIs1 << "\n"; */
			/* cout << "posis1: " << posIs1 << "\n"; */
			/* cout << "presis0: " << preIs0 << "\n"; */
			/* cout << "posis0: " << posIs0 << "\n"; */

			if(preIs1 && posIs1) cases_1++;
			else if(preIs0 && posIs0) cases_0++;
		}
	}
	
	string ans = "YES";

	/* cout << "cases_0: " << cases_0 << "\n"; */
	/* cout << "cases_1: " << cases_1 << "\n"; */
	for(int i=0; i<(int)r.size(); i++){
		if(r[i]=='0'){
			if(cases_0==0){
				if(cases_1==0){ 
					ans="NO"; break;
				}
				else cases_1--;
			}
		}
		if(r[i]=='1'){
			if(cases_1==0){
				if(cases_0==0){ 
					ans="NO"; break;
				}
				else cases_0--;
			}
		}
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
