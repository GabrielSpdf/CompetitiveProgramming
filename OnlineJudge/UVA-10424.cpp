//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int love(string s){
	int sum=0, ans=0;

	for(int i=0; i<(int)s.size(); i++){
		if((s[i]-96) >= 1 && (s[i]-96) <= 26){
			/* cout << "letra: " << s[i] << "\n"; */
			/* cout << "valor da letra: " << int(s[i] - 96)<<"\n"; */
			sum += int((s[i]- 96));
		}
	}

	string c = to_string(sum);

	while(c.size()>1){
		int ans=0;
		for(int i=0; i<(int)c.size(); i++){
			ans+= int(c[i] - 48);
		}
		c = to_string(ans);
	}

	ans = int(c[0] - 48);


	/* cout << "ans: " << ans << "\n"; */

	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);
	while(1){
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

		double n1, n2;

		n1 = double(love(s1));
		n2 = double(love(s2));

		/* cout << "n1: " << n1 << "\n"; */
		/* cout << "n2: " << n2 << "\n"; */

		/* cout << "**********\n"; */
		double c1, c2, ans;

		c1 = (n1/n2)*100;
		c2 = (n2/n1)*100;
		
		if(c1>100 && c2>100) ans = 100;
		else if(c1>100) ans = c2;
		else if(c2>100) ans = c1;
		else ans = max(c1, c2);

		/* cout << fixed << showpoint << setprecision(2) << (n1/n2)*100 << "\n"; */
		cout << fixed << showpoint << setprecision(2) << ans << " %" << "\n";
		/* cout << "**********\n"; */

		getline(cin, s1);
		if(s1.empty()) break;
		getline(cin, s2);
		if(s2.empty()) break;
	}



    return 0;
}
