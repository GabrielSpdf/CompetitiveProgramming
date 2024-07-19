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

	string s;
	while(cin >> s){
		if(s == "0") break;	

		int sum;
		while(s.size()>1){
			sum = 0;
			for(int i=0; i<(int)s.size(); i++){
				sum+=int(s[i] - 48);
			}

			s = to_string(sum);
		}

		cout << s << "\n";
	}


    return 0;
}
