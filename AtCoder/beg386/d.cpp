// Not solved
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
	int n, m;
	cin >> n >> m;
	set<ll> sl, sc;
	set<ll> bl, bc;
	for(int i=0; i<m; i++){
		int inp1, inp2;
		string inp3;

		cin >> inp1 >> inp2 >> inp3;
		
		if(inp3=="W"){
			sl.insert(inp1);
			sc.insert(inp2);
		}
		if(inp3=="B"){
			bl.insert(inp1);
			bc.insert(inp2);
		}
	}

	for(auto i=bl.begin(); i!=bl.end(); i++){
		set<ll>::iterator it =sl.lower_bound((*i));
		if(it!=sl.begin()){
			cout << "No\n";
			return;
		}
	}

	for(auto i=bc.begin(); i!=bc.end(); i++){
		set<ll>::iterator it =sc.lower_bound((*i));
		if(it!=sc.begin()){
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
