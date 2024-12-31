#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

map<ii, bool> visited;

int dfs(vector<vii> &grid, int i, int j, int n, int m){
	int yellow=0;
	
	if(visited[make_pair(i, j)]){
		return grid[i][j].second;
	}
	else{
		visited[make_pair(i, j)] = true;

		if(grid[i][j].first == 0) yellow = dfs(grid, i-1, j, n, m);
		else if(grid[i][j].first == 1) yellow = dfs(grid, i+1, j, n, m);
		else if(grid[i][j].first == 2) yellow = dfs(grid, i, j-1, n, m);
		else if(grid[i][j].first == 3) yellow = dfs(grid, i, j+1, n, m);
		else if(grid[i][j].first == 4) yellow = 0;

		grid[i][j].second = yellow;
	}
	
	return yellow;
}

void solve(){
	int n, m;
	cin >> n >> m;

	visited.clear();

	vector<vii> grid(n, vii(m));

	vii init;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char inp;
			cin >> inp;
			if(inp=='U') grid[i][j]=make_pair(0, 0);
			if(inp=='D') grid[i][j]=make_pair(1, 0);
			if(inp=='L') grid[i][j]=make_pair(2, 0);
			if(inp=='R') grid[i][j]=make_pair(3, 0);
			if(inp=='?') grid[i][j]=make_pair(4, 0);

			if(i==0 && grid[i][j].first == 0){ visited[make_pair(i, j)]=true; grid[i][j].second=-1; }
			else if(i==n-1 && grid[i][j].first == 1) { visited[make_pair(i, j)]=true; grid[i][j].second=-1; }
			else if(j==0 && grid[i][j].first == 2) { visited[make_pair(i, j)]=true; grid[i][j].second=-1; }
			else if(j==m-1 && grid[i][j].first == 3) { visited[make_pair(i, j)]=true; grid[i][j].second=-1; }
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dfs(grid, i, j, n, m);
		}
	}

	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j].first != 4 && grid[i][j].second != -1){
				ans++;
			}

			if(grid[i][j].first == 4){
				bool plus=false;

				if(i>0){
					if(grid[i-1][j].second != -1) plus=true;
				}
				if(j>0){
					if(grid[i][j-1].second != -1) plus=true;
				}
				if(i<n-1){
					if(grid[i+1][j].second != -1) plus=true;
				}
				if(j<m-1){
					if(grid[i][j+1].second != -1) plus=true;
				}

				ans+=plus;
			}
		}
	}

	cout << ans << "\n";
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
