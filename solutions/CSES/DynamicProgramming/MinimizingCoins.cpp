#include <bits/stdc++.h>
 
using namespace std;
 
const int32_t MAX = INT32_MAX;
 
typedef long long ll;
typedef vector<int> vi;
 
vi v(110, -1);
int memo[1000100];
 
int solve_dp(int target, int n){
    if(target<0) return 1000001;
    if(memo[target]!=-1) return memo[target];
 
    memo[target] = MAX;
    for(int i=0; i<n; i++){
        memo[target] = min(memo[target], solve_dp(target-v[i], n)+1);
    }
 
    return memo[target];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
	int n, target;
	cin >> n >> target;
 
    memset(memo, -1, sizeof(memo));
 
	for(int i=0; i<n; i++){ cin >> v[i]; memo[v[i]]=1; }
 
    memo[0] = 0;
 
    int ans = solve_dp(target, n);
 
    if(ans>=1000001) ans=-1;
 
    cout << ans << "\n";
 
    return 0;
}
