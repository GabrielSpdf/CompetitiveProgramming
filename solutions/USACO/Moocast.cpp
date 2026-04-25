#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const double EPS = 1e-9;

vector<tuple<int, int, double>> wt;
map<ii, vector<ii>> listAdj;
map<ii, bool> visited;
int node_counter;

double dist(int xa, int ya, int xb, int yb){
    return sqrtl(((xb-xa)*(xb-xa))+((yb-ya)*(yb-ya)));
}

void dfs(ii i){
    node_counter++;
    visited[i] = true;

    for(auto cur : listAdj[i]){
        if(visited[cur]) continue;
        dfs(cur);
    }
}

void solve(){
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int x, y; double p; cin >> x >> y >> p;
        wt.push_back({x, y, p});
    }

    for(int i=0; i<wt.size(); i++){
        int xa = get<0>(wt[i]);
        int ya = get<1>(wt[i]);
        for(int j=0; j<wt.size(); j++){
            if(i==j) continue;
            int xb = get<0>(wt[j]);
            int yb = get<1>(wt[j]);

            double debug = dist(xa, ya, xb, yb);
            if(debug - get<2>(wt[i]) <= EPS){
                listAdj[{xa, ya}].push_back({xb, yb});
            }
        }
    }

    int ans=0;
    for(int i=0; i<wt.size(); i++){
        node_counter = 0;
        dfs({get<0>(wt[i]), get<1>(wt[i])});
        ans = max(ans, node_counter);
        // cerr << "i | node_counter: " << i << " | " << node_counter << "\n";
        visited.clear();
    }
    cout << ans << "\n";
}

signed main(){
	setIO("moocast");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
