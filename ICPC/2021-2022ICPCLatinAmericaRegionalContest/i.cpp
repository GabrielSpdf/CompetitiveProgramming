#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi; // vector<vector<int>>
typedef vector<ii> vii; // vector<pair<int, int>>
typedef vector<bool> vb;

const int WEEK = 7;
const int SUM_OF_CYCLE = 91;

map<string, int> days = {
    {"Mon", 0},
    {"Tue", 1},
    {"Wed", 2},
    {"Thu", 3},
    {"Fri", 4},
    {"Sat", 5},
    {"Sun", 6}
};

vector<vii> adj;
vb in_main_cycle;

void solve(){
    string s; cin >> s;
    int n; cin >> n;

    adj = vector<vii>(5);
    adj[0].emplace_back(2, 30);
    adj[2].emplace_back(4, 30);
    adj[4].emplace_back(0, 31);
    adj[1].emplace_back(3, 30);
    adj[3].emplace_back(0, 32);
    in_main_cycle = vb(5);
    in_main_cycle[0] = true;
    in_main_cycle[2] = true;
    in_main_cycle[4] = true;

    vi v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int today = days[s];

    // 1. discover the day of each deposit
    vi dep_day(n);
    vi dep_dif(n);
    for(int i=0; i<n; i++){
        dep_day[i] = (WEEK+(today-(v[i]%WEEK)))%WEEK;
        dep_dif[i] = -v[i];
    }

    vi cand = dep_dif;
    for(int i=0; i<n; i++){
        int deficit = dep_dif[i];

        int j = dep_day[i];
        do{
            if(in_main_cycle[j] && abs(deficit)>SUM_OF_CYCLE){
                int gain = SUM_OF_CYCLE*(abs(deficit)/SUM_OF_CYCLE);
                cand[i] += gain;
                deficit += gain;
            }

            cand[i] += adj[j][0].second;
            deficit += adj[j][0].second;
            j = adj[j][0].first;
        }while(deficit<0);
    }

    int ans=LLONG_MAX;
    for(int i=0; i<n; i++){
        ans = min(ans, cand[i]);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
