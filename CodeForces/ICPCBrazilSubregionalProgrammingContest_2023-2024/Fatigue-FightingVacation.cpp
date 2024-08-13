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

	int d, c, r, qtd=0;
	cin >> d >> c >> r;

	ll et = d;

	vi ca(c), re(r);

	for(int i=0; i<c; i++) cin >> ca[i];

	for(int i=0; i<r; i++) cin >> re[i]; 

	/* sort(ca.begin(), ca.end()); */
	/* sort(re.begin(), re.end()); */

	int i=0, nextr=0;
	while(i<c){
		if((et-ca[i])<0){
			if(nextr<r){
				et+=re[nextr];
				nextr++;
				qtd++;
			}
			else break;
		}
		else{
			et-=ca[i];
			qtd++;
			i++;
		}
	}

	qtd += (r - nextr);

	cout << qtd << "\n";

    return 0;
}
