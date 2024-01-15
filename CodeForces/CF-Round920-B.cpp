//Accepted

#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll qtd, sum=0;
		int ud=0, zd=0;
		string s, u;

		cin >> qtd >> s >> u;

		vector<int> posu, posz;

		for(int i=0; i<qtd; i++){
			/* if(s[i]=='0'){ qz_s++; } */
			/* if(s[i]=='1'){ qu_s++; } */
			/* if(u[i]=='0'){ qz_u++; } */
			/* if(u[i]=='1'){ qu_u++; } */

			if(s[i]!=u[i] && s[i]=='1'){ posu.push_back(i); }
			if(s[i]!=u[i] && s[i]=='0'){ posz.push_back(i); }
		}

		for(int j=0; j<qtd; j++){
			if(s[j]!=u[j] && s[j]=='1'){
				if(!posz.empty()){ swap(s[j], s[posz.back()]); posz.pop_back(); sum++; }
				else{ sum++; }
			}
			else if(s[j]!=u[j] && s[j]=='0'){
				if(!posu.empty()){ swap(s[j], s[posu.back()]); posu.pop_back(); sum++; }
				else{ sum++; }
			}
		}

		cout << sum << endl;

		
	}


	return 0;
}


