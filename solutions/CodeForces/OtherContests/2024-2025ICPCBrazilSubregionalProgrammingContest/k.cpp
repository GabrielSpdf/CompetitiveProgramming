#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    // tie -> alice
    // alice starts
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    int t_sum=0;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        t_sum+=v[i];
    }
    if(t_sum%2){
        cout << "-1\n";
        return;
    }
    sort(v.begin(), v.end());

    vector<vector<bool>> dp(t_sum/2+1, vector<bool>(n+1, false));
    dp[0][0]=true;

    for(int k=1; k<=n; k++){
        for(int x=0; x<=t_sum/2; x++){
            if(x-v[k] >= 0){
                dp[x][k] = dp[x][k] | dp[x-v[k]][k-1];
            }
            dp[x][k] = dp[x][k] | dp[x][k-1];
        }
    }

    if(dp[t_sum/2][n]==false){
        cout << "-1\n";
        return;
    }

    vector<int> ali, bob;
    int x=t_sum/2;
    for(int k=n; k>=1; k--){
        if(dp[x][k-1]){
            bob.push_back(v[k]);
        }
        else{
            ali.push_back(v[k]);
            x-=v[k];
        }
    }

    int sum_ali=0, sum_bob=0;
    int i=0, j=0;
    for(int _=0; _<n; _++){
        if(sum_ali<=sum_bob){
            sum_ali+=ali[i];
            cout << ali[i];
            i++;
        }
        else{
            sum_bob+=bob[j];
            cout << bob[j];
            j++;
        }
        if(i+j<ali.size()+bob.size()) cout << " ";
        else cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
