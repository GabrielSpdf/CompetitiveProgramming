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
	int n, qm, qk;
	cin >> n >> qm >> qk;

	set<int> m;
	for(int i=0; i<qm; i++){
		int inp;
		cin >> inp;
		m.insert(inp);
	}
	
	set<int> k;
	for(int i=0; i<qk; i++){
		int inp;
		cin >> inp;
		k.insert(inp);
	}
	
	string s="";
	if(n==qk){
		for(int i=0; i<qm; i++) s+="1";
	}
	else if((n-qk)>=2){
		for(int i=0; i<qm; i++) s+="0";
	}
	else{
		for(auto question: m){
			if(k.find(question)!=k.end()){
				s+="0";
			}
			else{
				s+="1";
			}
		}
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
