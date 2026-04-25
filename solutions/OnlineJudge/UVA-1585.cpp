//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		
		int sum=0, aux=0;
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='O') aux++;
			else aux=0;

			sum+=aux;
		}

		cout << sum << "\n";

	}


    return 0;
}
