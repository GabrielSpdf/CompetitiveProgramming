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
		int l, mais=0, menos=0;
		string s;
		cin >> l >> s;

		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='+'){ mais++; }
			if(s[i]=='-'){ menos++; }
		}

		cout << abs(mais-menos) << endl;
	}



	return 0;
}


