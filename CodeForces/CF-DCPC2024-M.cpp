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

	vector<ll> k(t), n(t), ansA(t, -1), ans3(t, -1), ans2(t, -1);

	for(int i=0; i<t; i++){
		cin >> n[i] >> k[i];
	}

	for(int i=0; i<t; i++){
		ll kcopy = k[i], ncopy = n[i];

		while(kcopy >= 0){
			if(ncopy % 3 == 0) if((ncopy / 3 + (n[i] - (n[i] - (k[i] - kcopy)))) > ans3[i]) ans3[i] = (ncopy / 3 + (n[i] - (n[i] - (k[i] - kcopy))));

			if(ncopy % 2 == 0) if((ncopy / 2 + (n[i] - (n[i] - (k[i] - kcopy)))) > ans2[i]) ans2[i] = (ncopy / 2 + (n[i] - (n[i] - (k[i] - kcopy))));

			if(ncopy % 3 != 0 && ncopy % 2 != 0){
				ansA[i] = ncopy + (n[i] - (n[i] - (k[i] - kcopy)));
				break;
			}

			ncopy--;
			kcopy--;
		}

		/* cout << "ansA: " << ansA[i] << "\n"; */
		/* cout << "ans2: " << ans2[i] << "\n"; */
		/* cout << "ans3: " << ans3[i] << "\n"; */

		cout << max(ansA[i], max(ans2[i], ans3[i])) << "\n";	
	}

    return 0;
}

