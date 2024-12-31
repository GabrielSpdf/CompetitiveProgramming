//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, num=0, ver=0, n1=0;
		string s;
		cin >> n >> s;
		
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='1') { num++; n1++; }
			if(ver==0) if(i>0 && s[i-1]=='1' && s[i]=='1' && ver==0) { ver=1; num-=2; }
			else ver=0;
		}

		/* cout << "num: " << num << endl; */
		/* cout << "opr: " << num%2<< endl; */

		if((num%2)!=0 || (n1==2 && num==0)) { cout << "NO\n"; }
		else { cout << "YES\n"; }

	}


    return 0;
}
