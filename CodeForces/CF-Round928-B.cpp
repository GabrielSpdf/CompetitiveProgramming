//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string inp;
		string v[n];

		for(int k=0; k<n; k++){
			cin >> inp;
			v[k] = inp;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(v[i][j]=='1'){
					if(v[i+1][j+1]=='1' && v[i+1][j]=='1' && v[i][j+1]=='1'){
						cout << "SQUARE" << endl;
					}
					else{ cout << "TRIANGLE" << endl; }

					i=n; j=n;
				} 
			}
		}

	}


	return 0; 
}
