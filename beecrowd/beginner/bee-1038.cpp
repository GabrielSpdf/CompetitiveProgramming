//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;

double v[5]={4.0, 4.50, 5.0, 2.0, 1.50};

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	int x,y;
	cin >> x >> y;
	cout << "Total: R$ " << fixed << setprecision(2) << v[x-1]*y << "\n";


	return 0; 
}
