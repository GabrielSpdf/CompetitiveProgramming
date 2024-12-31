//Accepted

#include <bits/stdc++.h>

typedef long long ll;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

	int t;
	cin >> t;
	while(t--){
		int n, cont=0; 
		cin >> n; 

		vector<int> v(n); 
		vector<int> bo(101, 0); 
								
		for(int i=0; i<n; i++){
			cin >> v[i]; 
			bo[--v[i]]++; 
		}

		for(int i=0; i<101; i++){
			if(bo[i]>2){
				int aux;
				aux = bo[i];
 
				cont+= aux/3;
			}
		}

		cout << cont << "\n";
	}


    return 0;
}
