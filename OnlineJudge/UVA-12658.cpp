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

	int n;
	cin >> n;

	vector<string> alph = {".*.", "*..", "..*"};
	vector<string> ver = {"1", "2", "3"};

	vector<string> vs;
	for(int i=0; i<5; i++){
		string s;
		cin >> s;
		vs.push_back(s);
	}

	string ans;
	for(int j=0; j<(4*n); j+=4){
		string aux;
		
		aux = vs[3].substr(j, 3);

		/* cout << "aux: " << aux << "\n"; */

		for(int k=0; k<(int)alph.size(); k++){
			/* cout << "alph[k]: " << alph[k] << "\n"; */
			
			if(aux == alph[k]){
				/* cout << "igual\n"; */
				ans += ver[k];
				break;
			}
		}
	}

	cout << ans << "\n";


    return 0;
}
