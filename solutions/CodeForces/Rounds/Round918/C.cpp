//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long n;
		long long val, sum=0, inp;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>inp;
			sum+=inp;
		}

		val=sqrt(sum);
		/* cout << "val: " << val << endl; */
		/* cout << "sum: " << sum << endl; */

		if(val*val == sum){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}
