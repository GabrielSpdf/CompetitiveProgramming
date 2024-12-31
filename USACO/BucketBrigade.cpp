//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	vector<string> vs(10);
	string s;
	int bi, bj, li, lj, ri, rj, ans;

	for(int i=0; i<10; i++){
		cin >> vs[i];
	}

	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(vs[i][j]=='B'){ bi=i; bj=j; }
			if(vs[i][j]=='L'){ li=i; lj=j; }
			if(vs[i][j]=='R'){ ri=i; rj=j; }
		}
	}
	
	
	/* cout << "bi & bj: " << bi << " " << bj << endl; */
	/* cout << "li & lj: " << li << " " << lj << endl; */

	ans = abs(bi-li)+abs(bj-lj);
	if((ri == bi && ri == li && ((rj>bj && rj<lj) || (rj>lj && rj<bj))) || (rj == bj && rj == lj && ((ri>bi && ri<li) || (ri>li && ri<bi)))) ans+=1;
	else ans-=1;
	cout << ans << "\n";



    return 0;
}
