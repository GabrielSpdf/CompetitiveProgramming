//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, inp;
	cin >> n;
	vector<bool> ver(n, false);

	for(int i=0; i<(n-1); i++){
		cin >> inp;
		ver[inp-1]=true;
	}
	for(int j=0; j<n; j++){
		if(ver[j]==false){ cout << (j+1) << endl; return 0; }
	}


	return 0;
}
