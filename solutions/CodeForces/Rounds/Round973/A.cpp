// Accepted

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

	//n fruits
	//x fruits per second
	//each second zhan can put y fruits
	//c fruits inside the blender
	//blend min(x,c)
	//
	int t;
	cin >> t;
	while(t--){
		int n, x, y;

		cin >> n >> x >> y;

		cout << (n+min(x, y)-1)/min(x, y) << "\n";
	}


    return 0;
}
