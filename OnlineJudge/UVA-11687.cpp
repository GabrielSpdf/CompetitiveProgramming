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

	string s;
	while(cin >> s){
		if(s == "END") break;

		string aux = to_string(s.size()); 

		int i=1;
		while(s != aux){
			s = to_string(s.size()); 
			aux = to_string(s.size()); 
			i++;
		}

		cout << i << "\n";
	}


    return 0;
}
