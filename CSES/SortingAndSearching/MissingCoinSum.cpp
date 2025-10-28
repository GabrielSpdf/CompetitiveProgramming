#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, bool> freq;
    for(auto &a: v){
        cin >> a;
    }
    sort(v.begin(), v.end());
    int mx_sum=0;
    for(int i=0; i<n; i++){
        if(v[i]>mx_sum+1){
            cout << mx_sum+1 << "\n";
            return;
        }
        else{
            mx_sum+=v[i];
        }
    }
    cout << mx_sum+1 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
