//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
const double pi = atan(1)*4;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	double a, b, c, cos1, cos2, cos3, area, num;

	cin >> a >> b >> c;

	cos1 = acos(((a*a)-(b*b)-(c*c))/(2*b*c));
	cos2 = acos(((b*b)-(a*a)-(c*c))/(2*a*c));
	cos3 = acos(((c*c)-(a*a)-(b*b))/(2*a*b));

	cos1 = (180*cos1)/pi;
	cos2 = (180*cos2)/pi;
	cos3 = (180*cos3)/pi;

	/* cout << cos1 << " " << cos2 << " " << cos3 << "\n"; */

	area = cos1+cos2+cos3;

	if(int(abs(area-360)) == 0 && cos1 && cos2 && cos3) cout << fixed << setprecision(1) << "Perimetro = " << a+b+c << "\n";
	else cout << fixed << setprecision(1) << "Area = " << ((a+b)*c)/2 << "\n";


	return 0; 
}

