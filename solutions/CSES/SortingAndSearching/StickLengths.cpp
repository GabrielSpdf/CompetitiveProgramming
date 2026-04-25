#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &a: v){
        cin >> a;
    }
    sort(v.begin(), v.end());

    int mid1=v[(v.size()-1)/2], mid2=v[(v.size()+2)/2];
    int ans1=0, ans2=0;
    for(int i=0; i<n; i++){
        ans1+=abs(v[i]-mid1);
        ans2+=abs(v[i]-mid2);
    }

    cout << min(ans1, ans2) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
