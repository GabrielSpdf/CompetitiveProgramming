#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9;

int n, xl, yl, xb, yb;
map<int, vector<ii>> mpx;
map<int, vector<ii>> mpy;
map<ii, int> dist;
map<ii, int> past;

int bfs(int st){
    queue<ii> q;
    q.push({xl, yl});
    dist[{xl, yl}] = 1;
    past[{xl, yl}] = st;

    while(!q.empty()){
        ii curr = q.front();
        q.pop();

        vector<ii> v;
        if(past[curr]==1) v = mpx[curr.first];
        else if(past[curr]==2) v = mpy[curr.second];

        for(auto [r, c] : v){
            if(dist[{r, c}] != 0) continue;
            dist[{r,c}] = dist[{curr.first, curr.second}] + 1;
            past[{r, c}] = 3 - past[curr];

            if(r == xb && c == yb){
                return dist[{r, c}];
            }
            q.push({r, c});
        }
    }
    return INF;
}

void solve(){
    cin >> n >> xl >> yl >> xb >> yb;
    mpx[xl].push_back({xl, yl});
    mpy[yl].push_back({xl, yl});
    mpx[xb].push_back({xb, yb});
    mpy[yb].push_back({xb, yb});

    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        mpx[x].push_back({x, y});
        mpy[y].push_back({x, y});
    }

    int ans = INF;
    for(int i=1; i<3; i++){
        ans = min(ans, bfs(i));
        dist.clear();
        past.clear();
    }
    cout << (ans == INF? -1 : ans-2) << "\n";
}

signed main(){
	setIO("lasers");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
