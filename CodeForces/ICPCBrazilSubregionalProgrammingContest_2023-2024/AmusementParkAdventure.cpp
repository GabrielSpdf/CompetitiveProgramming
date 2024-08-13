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

	int n, h;
	cin >> n >> h;

	vi a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	int cont=0;
	for(int i=0; i<(int)a.size(); i++){
		if(h >= a[i]) cont++;
		else break;
	}

	cout << cont << "\n";


    return 0;
}
