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
 
	int n;
	cin >> n;
	set<int> s;
	for(int i=0; i<n; i++){
		int inp;
		cin >> inp;
		s.insert(inp);
	}
 
	cout << s.size() << "\n";
 
 
    return 0;
}
