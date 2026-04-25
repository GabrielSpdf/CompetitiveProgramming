#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void permute(string select, string remain){
    if(remain == ""){
        cout << select << endl;
        return;
    }
    for(int i=0;remain[i];++i){
        string wk(remain);
        permute(select + remain[i], wk.erase(i, 1));
    }
}

void solve(){
	string n;
	cin >> n;

	sort(n.begin(), n.end());
	permute("", n);
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
