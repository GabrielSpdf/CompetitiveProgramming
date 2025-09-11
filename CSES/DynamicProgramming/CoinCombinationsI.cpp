#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

void abacate(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &a: v) cin >> a;

    // vector<vector<int>> memo(n, vector<int>(x));
    int memo[100][1000000];
    int sum_there[1000001];
    // vector<int> sum_there(x+1);

    for(int i=0; i<=x; i++)
        sum_there[i] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<x; j++){
            memo[i][j] = 0;            
        }
    }

    for(int i=0; i<n; i++){
        // v[i] can be greater than x (PROBLEM) -> SOLVED
        if(v[i]<x)
            memo[i][v[i]] = (memo[i][v[i]] + 1) % MOD;
        if(v[i]==x)
            sum_there[x] = (sum_there[x] + 1) % MOD;
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<n; j++){
            if((i-v[j])>=0 && (i-v[j])<x){
                memo[j][i] = (memo[j][i] + sum_there[i-v[j]]) % MOD;
                sum_there[i] = (sum_there[i] + memo[j][i]) % MOD;
            }
        }
    }

    for(int i=0; i<n; i++){
        if((x-v[i])>=0 && (x-v[i])<=x){
            sum_there[x] = (sum_there[x] + sum_there[x-v[i]]) % MOD;
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=x; j++){
    //         cerr << memo[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    cout << sum_there[x] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    abacate();
}