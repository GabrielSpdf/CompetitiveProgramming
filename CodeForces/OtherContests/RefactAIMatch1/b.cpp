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
	string s, t;
    cin >> n >> s >> t;

    int count0 = 0, count1=0;

    for (int i=0; i<n; i++) {
		if(s[i]=='0')count0++;
		else count1++;
    }
	
	string ans = "YES";
    for (int i=0; i<(n-1); i++){
        if (!count1 || !count0){ ans = "NO"; break; }
        if (t[i] == '0') count1--;
        else count0--;
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
