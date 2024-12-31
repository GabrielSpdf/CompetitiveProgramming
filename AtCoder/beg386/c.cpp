#include <bits/stdc++.h>

using namespace std;

const int32_t MAX = INT32_MAX;
const int32_t MIN = INT32_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int k;
	string s, t;
	cin >> k >> s >> t;

	int dif1=0, dif2=0, dif3=0;
	
	if((int)s.size()-(int)t.size()==0){
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]!=t[i]) dif1++;
		}
	}
	else dif1=MAX;
	
	int idxs1=0, idxt1=0;
	if(abs((int)s.size()-(int)t.size())<2){
		while(idxs1<(int)s.size() && idxt1<(int)t.size()){
			if(s[idxs1]!=t[idxt1]){
				idxs1++;
				dif2++;
			}
			else{
				idxs1++;
				idxt1++;
			}
		}
	}
	else dif2=MAX;

	int idxs2=0, idxt2=0;
	if(abs((int)s.size()-(int)t.size())<2){
		while(idxs2<(int)s.size() && idxt2<(int)t.size()){
			if(s[idxs2]!=t[idxt2]){
				idxt2++;
				dif3++;
			}
			else{
				idxs2++;
				idxt2++;
			}
		}
	}
	else dif3=MAX;

	/* cout << "dif1: " << dif1 << "\n"; */
	/* cout << "dif2: " << dif2 << "\n"; */
	/* cout << "dif3: " << dif3 << "\n"; */

	if(dif1<2 || dif2<2 || dif3<2){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
