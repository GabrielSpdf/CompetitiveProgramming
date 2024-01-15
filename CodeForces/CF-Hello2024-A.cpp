//Accepted

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--){
		int a,b, sum;
		cin >> a >> b;
		sum=a+b;
		if(sum%2==0){cout << "Bob" << endl;}
		else{ cout << "Alice" << endl; }
	}





	return 0;
}
