//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;


		if(n%2 != 0) cout << "NO\n";
		else{
			for(int i=0; i<n/2; i++){
				if(i%2) s+="AA";
				else s+="BB";
			}

			cout << "YES\n" << s << "\n";
		}
	}


    return 0;
}
