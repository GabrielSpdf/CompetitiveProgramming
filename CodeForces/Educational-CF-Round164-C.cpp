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
		int ver=0;
		string x, y, aux1, aux2;
		cin >> x >> y;

		for(ll i=0; i<(ll)x.size(); i++){
			if(x[i]!=y[i] && ver==0){
				if(x[i]>y[i]){ aux1.append(to_string(x[i]-48)); aux2.append(to_string(y[i]-48)); }
				else{ aux1.append(to_string(y[i]-48)); aux2.append(to_string(x[i]-48)); }
				ver=1;
			}
			else{
				if(x[i]>y[i]){ aux1.append(to_string(y[i]-48)); aux2.append(to_string(x[i]-48)); }
				else{ aux1.append(to_string(x[i]-48)); aux2.append(to_string(y[i]-48)); }
			}

		}

		cout << aux1 << "\n" << aux2 << "\n";
	}


    return 0;
}
