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
	int n, d;
	cin >> n >> d;

	set<int> ans;
	ans.insert(1);
	
	if(n<3){
		string s = "";
		for(int i=0; i<n; i++) s+=to_string(d);

		for(int i=1; i<=9; i+=2){
			if(stoi(s)%i==0) ans.insert(i);
		}
	}
	else{
		if(n>=3 || d==3) ans.insert(3);
		if(d==5) ans.insert(5);
		if(n>=3 || d==7) ans.insert(7);
		if(n>=6 || (n>=3 && (d==9 || d==6 || d==3)) || d==9) ans.insert(9);
	}

	for(auto num : ans) cout << num << " ";
	cout << "\n";
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
