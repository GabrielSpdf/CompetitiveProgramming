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

	int n, l, minus;
	cin >> n >> l;
	vi v(n);
	for(int i=0; i<n; i++){
		cin >> minus;
		v[i] = 100 - minus;
	}


	sort(v.begin(), v.end());
	int index=0, count=0;
	for(int i=0; i<n; i++){
		l -= v[index];
		if(l<0) break;
		count++;
		index++;
	}

	cout << count << "\n";



    return 0;
}
