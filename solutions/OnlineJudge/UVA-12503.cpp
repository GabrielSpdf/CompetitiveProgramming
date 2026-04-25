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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> vs(n);
		cin.ignore();

		for(int i=0; i<n; i++){
			string s, aux;
			getline(cin, s);

			if(s == "LEFT" || s == "RIGHT") vs[i]=s;
			else{
				for(int j=8; j<(int)s.size(); j++){
					aux+=s[j];
				}
				vs[i]=vs[stoi(aux)-1];
			}
		}

		int sum=0;
		for(int i=0; i<n; i++){
			if(vs[i]=="RIGHT") sum++;
			else sum--;
		}

		cout << sum << "\n";
	}


    return 0;
}
