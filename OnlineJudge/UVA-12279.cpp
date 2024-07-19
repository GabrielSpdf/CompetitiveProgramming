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

	int t, cs=1;
	cin >> t;
	while(t!=0){
		vi v(t);
		int sum=0;

		for(int i=0; i<t; i++){
			cin >> v[i];
		}
	
		for(int i=0; i<t; i++){
			if(v[i]==0) sum--;
			else sum++;
		}

		cout << "Case " << cs << ": " << sum << "\n";

		cin >> t;
		cs++;
	}


    return 0;
}
