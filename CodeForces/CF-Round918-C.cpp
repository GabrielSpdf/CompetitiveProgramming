//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long n;
		double val, sum=0.0, inp;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>inp;
			sum+=inp;
		}
		/* cout << "sqrt: " << sqrt(sum) << endl; */

		val=sqrt(sum);
		if(val-(int)val == 0){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}
