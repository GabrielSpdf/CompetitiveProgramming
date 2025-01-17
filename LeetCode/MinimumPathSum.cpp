#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define int long long
#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

vvi memo;
vvi grid;

int dp_ans(int i, int j, int n, int m){
	if(i==0 && j==0) return grid[0][0];

	if(i<0 || j<0) return INT_MAX;
	
	if(memo[i][j]==0){
		memo[i][j] = grid[i][j] + min(dp_ans(i-1, j, n, m), dp_ans(i, j-1, n, m));
	}

	return memo[i][j];
}	

void solve(){
	int n, m;
	cin >> n >> m;

	memo = vvi(n+1, vi(m));
	grid = vvi(n+1, vi(m));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> grid[i][j];
			memo[i][j]=0;
		}
	}
	
	memo[0][0] = grid[0][0];
	for(int i=1; i<n; i++) memo[i][0] += grid[i][0] + memo[i-1][0];
	for(int j=1; j<m; j++) memo[0][j] += grid[0][j] + memo[0][j-1];
	
	dp_ans(n-1, m-1, n, m);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cerr << memo[i][j] << " ";
		}
		cerr << "\n";
	}
	cerr << "\n";

	cout << memo[n-1][m-1] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}

/* leet code format
 * class Solution {
public:
    vector<vector<int>> memo;
    int dp_ans(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        
        if(memo[i][j]==0){
            memo[i][j] = grid[i][j] + min(dp_ans(grid, i-1, j, n, m), dp_ans(grid, i, j-1, n, m));
        }

        return memo[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) { 
        int n = grid.size();
        int m = grid[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
			    memo[i][j]=0;
		    }
	    }  

        memo[0][0] = grid[0][0];
        for(int i=1; i<n; i++) memo[i][0] += grid[i][0] + memo[i-1][0];
	    for(int j=1; j<m; j++) memo[0][j] += grid[0][j] + memo[0][j-1];

        dp_ans(grid, n-1, m-1, n, m);

        return memo[n-1][m-1];
    }
};
*/
