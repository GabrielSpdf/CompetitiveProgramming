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
	cin >> n;
	
	vi par, impar;
	for(int i=1; i<=n; i++){
		if(i!=1 && i!=2 && i!=3 && i!=4 && i!=5){
			if(i%2){ //impar
				impar.push_back(i);
			}
			else par.push_back(i);
		}
	}

	if(n<5) cout << "-1\n";
	else{
		for(int i=0; i<(int)impar.size(); i++){
			cout << impar[i] << " ";
		}
		cout << "1 3 5 4 2 ";
		for(int i=0; i<(int)par.size(); i++){
			cout << par[i] << " ";
		}
		cout << "\n";
	}
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
