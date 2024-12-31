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

	string s;
	cin >> s;

	if(s.size()>2){
		if(s[s.size()-1]=='n' && s[s.size()-2]=='a' && s[s.size()-3]=='s') cout << "Yes\n";
		else cout << "No\n";
	}
	else cout << "No\n";


    return 0;
}

