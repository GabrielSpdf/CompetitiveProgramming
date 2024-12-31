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

	reverse(s.begin(), s.end());

	for(int i=0; i<(int)s.size(); i++){
		if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	}

	cout << s << "\n";
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
