//Accepted

#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;
 
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);
 
	int t;
	cin >> t;
	while(t--){
		int n, m, k, ans;
		cin >> n >> m >> k;
 
		//n parts
		//m colors
		//k bob
 
		ans = n/m;
		if(n%m != 0) ans+=1;
		
		if(m > 1 && (n-ans) > k){ cout << "YES\n"; }
		else{
			cout << "NO\n";
		}
 
	}
 
 
	return 0; 
}
