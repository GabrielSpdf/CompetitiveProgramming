#include <bits/stdc++.h>
#include <climits>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const long long MAX = LONG_LONG_MAX;
const long long MIN = LONG_LONG_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int a, b, c;

	cin >> a >> b >> c;

	int sum1, sum2, sum3;

	map<int, int> ans;
	
	ans[a]++;
	ans[b]++;
	ans[c]++;
	ans[a+b]++;
	ans[a+c]++;
	ans[b+c]++;
	ans[a+b+c]++;
	
	for(auto i=ans.begin(); i!=ans.end(); i++){
		if((*i).second>1){ cout << "Yes\n"; return ;}
	}
	cout << "No\n";
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

