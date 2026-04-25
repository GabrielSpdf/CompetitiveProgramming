#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

vector<vi> listAdj;
vector<bool> visited;
vi rd;

void count(int idx, int cnt){
	if(!visited[idx]) cnt++;
	visited[idx]=true;

	if(listAdj[idx].size()==0) rd[idx]+=cnt;
	else rd[idx]=cnt;

	for(auto nxt : listAdj[idx]) count(nxt, cnt);
}

void solve(){
	int n;
	cin >> n;
	
	listAdj = vector<vi>(n);
	visited = vector<bool>(n, false);
	rd = vi(n, 0);
	for(int i=0; i<(n-1); i++){
		int a, b;
		cin >> a >> b; a--; b--;

		listAdj[a].push_back(b);
	}

	for(int i=0; i<n; i++) count(i, 0);
	
	int ans=101;
	for(int i=0; i<rd.size(); i++){
		/* cout << rd[i] << "\n"; */
		if(rd[i]==n) ans=min(i, ans);
	}

	if(ans!=101) cout << ans+1 << "\n";
	else cout << -1 << "\n";
}

int main(){
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
