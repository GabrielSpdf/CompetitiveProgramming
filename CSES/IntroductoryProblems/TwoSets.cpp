#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;


void solve(){
	int n;
	cin >> n;
	
	if(n%2==0){
		if((n/2)%2) return void(cout << "NO\n");
		cout << "YES\n";
		cout << n/2 << "\n";
		for(int i=0; i<n/4; i++){
			cout << i+1 << " ";
		}
		for(int i=0; i<n/4; i++){
			cout << n-i << " ";
		}
		cout << "\n";
		cout << n/2 << "\n";
		for(int i=0; i<n/4; i++){
			cout << i+n/4+1 << " ";
		}
		for(int i=0; i<n/4; i++){
			cout << n-n/4-i << " ";
		}
	}
	else{
		if(((n-3)/2)%2) return void(cout << "NO\n");
		cout << "YES\n";
		cout << ((n-3)/2 + 2) << "\n";
		cout << "1 2 ";
		for(int i=0; i<n/4; i++){
			cout << i+4 << " ";
		}
		for(int i=0; i<n/4; i++){
			cout << n-i << " ";
		}
		
		int tam=(n-3)/2 + 1;
		cout << "\n";
		cout << tam << "\n";
		cout << "3 ";
		for(int i=0; i<n/4; i++){
			cout << i+(n/4)+4 << " ";
		}
		for(int i=0; i<n/4; i++){
			cout << n-(n/4)-i << " ";
		}
		cout << "\n";
	}
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
