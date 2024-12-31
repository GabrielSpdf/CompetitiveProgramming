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
	string s;
	cin >> s;

	int ans=0, count=0;
	vi zeros;
	for(int i=1; i<=(int)s.size(); i++){
		if(s[i-1]!='0'){
			ans++;
			zeros.push_back(count);
			count=0;
		}
		if(s[i-1]=='0'){
			count++;
		}
	}
	zeros.push_back(count);

	for(int i=0; i<zeros.size(); i++){
		ans += zeros[i]/2;
		ans += zeros[i]%2;
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
