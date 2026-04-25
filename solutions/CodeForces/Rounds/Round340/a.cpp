#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int ans=0;
	/* brute force O(n) */
	/*
	while(n>0){
		if(n-5>=0)
			n-=5;
		else if(n-4>=0)
			n-=4;
		else if(n-3>=0)
			n-=3;
		else if(n-2>=0)
			n-=2;
		else if(n-1>=0)
			n-=1;

		ans++;
	}
	*/

	/* trick idea O(1) */
	ans = ((n+4)/5);

	cout << ans << "\n";

	return 0;
}
