//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, inp, ver, cont=0, maior=0;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> inp;
		if(inp<maior){ cont+=(maior-inp); inp=maior; }
		else{ maior = inp;}

		if(i>0 && (inp-maior)<0){ cont+=(maior-inp); }

		ver = inp;
	}

	cout << cont << endl;

	return 0;
}
