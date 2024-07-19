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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	vector<string> vs = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
	vector<string> lang = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};

	string s, ans;
	cin >> s;
	int i=1;

	while(s != "#"){
		ans = "UNKNOWN";
		for(int i=0; i<(int)vs.size(); i++){
			if(s == vs[i]) ans = lang[i];
		}

		cout << "Case " << i << ": " << ans << "\n";

		cin >> s;
		i++;
	}



    return 0;
}
