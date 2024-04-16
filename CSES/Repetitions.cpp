//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll ver=0, maior=0;
	char z;
	string x;

	cin >> x;

	for(ll i=0; i<(ll)x.size(); i++){
		if(i>0 && z==x[i]){ 
			ver++; 
			if(ver>maior){ maior=ver; } 
		}
		else{ ver=0; }
		z = x[i];
	}

	cout << maior+1 << endl;


	return 0;
}
