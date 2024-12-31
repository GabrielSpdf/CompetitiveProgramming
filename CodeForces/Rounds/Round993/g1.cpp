#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> listAdj;
vi visited;
vi path;
vi dist;
int sum;

// 0 not visited
// 1 visited
// 2 visited loop
// 3 visited not loop

void dfs(int idx){
	if(visited[idx]==2 || visited[idx]==3) return;

	if(visited[idx]==1){
		visited[idx]=2;
		dfs(listAdj[idx][0]);
		return;
	}

	visited[idx]=1;
	path.push_back(idx);
	for(int i=0; i<listAdj[idx].size(); i++){
		dfs(listAdj[idx][i]);
	}
}

void run_ans(int idx){
	if(visited[idx]==2) return;
	if(dist[idx]!=0){
		sum = dist[idx];
		return;
	}

	path.push_back(idx);

	int max_dist = dist[idx];
	for(int i=0; i<listAdj[idx].size(); i++){
		run_ans(listAdj[idx][i]);
	}
}

void solve(){
	int n;
	cin >> n;

	listAdj.clear();
	visited.clear();

	listAdj = vector<vi>(n);
	visited = vi(n, 0);
	dist = vi(n, 0);

	vi noincoming;
	vector<bool> noincoming_helper(n);

	for(int i=0, inp; i<n && cin>>inp; i++){
		listAdj[i].push_back(inp-1);
		noincoming_helper[inp-1] = true;
	}

	for(int i=0; i<n; i++){
		if(noincoming_helper[i]==false) noincoming.push_back(i);
	}
	
	/* cout << "noincoming: "; */
	/* for(int i=0; i<noincoming.size(); i++) cout << noincoming[i] << " "; */
	/* cout << "\n"; */

	for(int i=0; i<noincoming.size(); i++){
		path.clear();
		dfs(noincoming[i]);

		for(int j=0; j<path.size(); j++){
			if(visited[path[j]]==1) visited[path[j]]=3;
		}
	}
	
	/* cout << "visited\n"; */
	/* for(int i=0; i<n; i++){ */
	/* 	cout << i+1 << ": " << visited[i] << "\n"; */
	/* } */
	/* cout << "\n"; */
	
	for(int i=0; i<noincoming.size(); i++){
		path.clear();
		sum=0;
		run_ans(noincoming[i]);	
		reverse(path.begin(), path.end());

		for(int i=0; i<path.size(); i++){
			dist[path[i]]=(i+1)+sum;
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		ans = max(ans, dist[i]);
	}

	cout << ans+2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}

