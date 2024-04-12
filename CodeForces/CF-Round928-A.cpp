//Accepted

#include <bits/stdc++.h>

using namespace std;
	
typedef long long ll;

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	ll n;
	cin >> n;
	while(n--){
		string s;
		ll ver1=0, ver2=0;
		cin >> s;

		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='A') ver1++;
			else{ ver2++; }
		}

		cout << (ver1 > ver2? "A" : "B") << endl;
	}

	return 0; 
}
