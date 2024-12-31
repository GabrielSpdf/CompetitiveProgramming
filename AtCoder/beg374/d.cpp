#include <algorithm>
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

vector<string> comb;

double cD(int x1, int y1, int x2, int y2){
	double dist = sqrtl(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));

	return dist;
}

void genSeq(int n, string& aux, int i){
	if(n == i){
		comb.push_back(aux);
		return;
	}
	
	aux[i] = '0';
	genSeq(n, aux, i+1);
	
	aux[i] = '1';
	genSeq(n, aux, i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n, s, t;
	cin >> n >> s >> t;
	string aux = string(n, '0');

	genSeq(n, aux, 0);

	vector<tuple<int, int, int, int>> vt;

	for(int i=0; i<n; i++){
		int inp1, inp2, inp3, inp4;

		cin >> inp1 >> inp2 >> inp3 >> inp4;
		vt.emplace_back(inp1, inp2, inp3, inp4);
	}

	sort(vt.begin(), vt.end());

	double ans=INT_MAX;
	do{
		for(int i=0; i<(int)comb.size(); i++){
			int x=0, y=0;
			double time=0;
			for(int j=0; j<n; j++){
				auto [a, b, c, d] = vt[j];

				int s1, s2, e1, e2;

				if(comb[i][j]=='1'){
					s1 = a;
					s2 = b;
					e1 = c;
					e2 = d;
				}
				else{
					s1 = c;
					s2 = d;
					e1 = a;
					e2 = b;
				}

				time += cD(x, y, s1, s2) / double(s);
				time += cD(s1, s2, e1, e2) / double(t);
				x = e1;
				y = e2;
			}

			ans = min(ans, time);
		}
	}while(next_permutation(vt.begin(), vt.end()));
	
	cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}

