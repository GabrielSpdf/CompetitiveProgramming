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
vi visited;
int cnt;

void solve(){
	int n, m;
	cin >> n >> m;
	
	listAdj.clear();
	listAdj = vector<vi>(n);
	visited = vi(n, 1);
	cnt=1;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}
	
	for(int i=0; i<n; i++) sort(listAdj[i].begin(), listAdj[i].end());

	for(int i=1; i<n; i++){
		for(auto nxt : listAdj[i]){
			if(visited[nxt]==visited[i])
			{
				if(nxt<i) visited[i]++;
				if(nxt>i) visited[nxt]++;
			}
		}
	}

	for(int i=0; i<n; i++) cout << visited[i];
	cout << "\n";
}

int main(){
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
