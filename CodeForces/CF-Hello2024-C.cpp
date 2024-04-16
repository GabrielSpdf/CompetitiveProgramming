//Accepted

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int qtd;
		ll sum=0, a, lim1, lim2;
		lim1 = 1e9; lim2 = 1e9;
		cin >> qtd;
		for(int i=0; i<qtd; i++){
			cin >> a;
			if(lim1>lim2){ swap(lim1, lim2); }
			if(a<=lim1){ lim1 = a; }
			else if(a<=lim2){ lim2 = a; }
			else{ sum++; lim1=a; }
		}

		cout << sum << endl;
	}



	return 0;
}


