//Accepted

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

int main(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int len, qtdneg=0, qtdz=0;

		cin >> len;

		for(int j=0; j<len; j++){
			ll inp;
			cin >> inp;
			if(inp<0){qtdneg++;}
			if(inp==0){qtdz++;}
		}

		if(qtdz || qtdneg%2){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
			cout << 1 << " " << 0 << endl;
		}
	}

	return 0;
}
