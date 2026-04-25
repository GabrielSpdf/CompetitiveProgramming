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
	
	int diff=0;
	for(int i=2; i<(int)s.size(); i++){
		if(s[i-1]==s[i-2]){ cout << s[i-1] << s[i-2] << "\n"; return; }

		if(s[i]!=s[i-1] && s[i-1]!=s[i-2] && s[i-2]!=s[i]){
			cout << s[i-2] << s[i-1] << s[i] << "\n";
			return;
		}
	}
	
	if(s.size()>=2 && s[(int)s.size()-1] == s[(int)s.size()-2]){
		cout << s[(int)s.size()-1] << s[(int)s.size()-2] << "\n";
		return;
	}


	cout << -1 << "\n";
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
