//Accepted

#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define ll long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, sum=0;
		cin >> n;
		ll max=0, min=10e9;
		vector<ll> dif;

		for(int i=0; i<n; i++){
			int a;
			ll b;
			cin >> a >> b;
			if(a==1){
				if(b>max){ max=b; }
			}
			if(a==2){
				if(b<min){ min=b; }
			}
			if(a==3){
				dif.push_back(b);
			}
		}

		/* cout << "max: " << max << endl; */
		/* cout << "min: " << min << endl; */
		/* cout << "entrou" << endl; */
		if(min<max){ cout << sum << endl; dif.clear(); continue; }
		/* cout << "entrou1" << endl; */
		/* cout << "max: " << max << endl; */
		/* cout << "min: " << min << endl; */

		while(!dif.empty()){
			if(dif.back() >= max && dif.back() <= min){ sum--; }
			dif.pop_back();
		}
		/* cout << "entrou2" << endl; */

		/* cout << sum << endl; */
		sum += min-max+1;
		cout << sum << endl;
	}



	return 0;
}


