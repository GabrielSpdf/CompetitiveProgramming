//Accepted

#include <bits/stdc++.h>

using namespace std;


int main(){
	int n, inp, cont=0, ans=0, sum;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>inp;
		cont+=inp;
	}

	sum =(1+n+1);
	while(cont>=sum){ sum+=(n+1); }

	/* cout << "sum init: " << sum << endl; */

	for(int j=1; j<6; j++){
		int a=cont+j;
		/* cout << "a: " << a << endl; */
		/* cout << "sum: " << sum << endl; */
		/* cout << "a op sum: " << a%sum << endl; */
		if(a%sum != 0){ ans++; }
		else{ sum+=(n+1); }
	}

	cout << ans << endl;

	return 0;
}

//1th
//1+nth+(nth+1)
