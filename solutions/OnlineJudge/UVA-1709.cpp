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

double price(double k, double p, double a, double b, double c, double d){
	return p*((sin(a*k+b))+cos(c*k+d)+2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	string s;
	double p, a, b, c, d, n;
	
	while(cin >> p >> a >> b >> c >> d >> n){
		//price(k) = p · (sin(a · k + b) + cos(c · k + d) + 2)
		
		double maior;
		vector<double> v(n);
		for(int i=1; i<=n; i++){
			v[i-1] = price(i, p, a, b, c, d);
		}

		/* cout << "v: "; */
		/* for(int i=0; i<n; i++){ */
		/* 	cout << v[i] << " "; */
		/* } */

		/* cout << "\n"; */

		maior = v[0];

		vector<double> dec;

		for(int i=1; i<n; i++){
			if(v[i]>=maior){
				maior=v[i];
			}
			else{
				dec.push_back(maior - v[i]); 
			}
		}

		if(!dec.empty()){
			double ans = *max_element(dec.begin(), dec.end()); 
			cout << fixed << showpoint << setprecision(6) << ans << "\n";
		}
		else cout << "0.00\n";

	}

	


    return 0;
}
