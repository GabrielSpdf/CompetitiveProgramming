
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

// esboco pre exercicio
// 1. encontrar cada componente conexa
// 2. em cada componente conexa, encontrar o x_min, y_min e x_max e y_max
// 3. ele quer o perimetro entao: 2*(x_max - x_min) + 2*(y_max - y_min)
// 4. entre todas as componentes conexas, pegar o menor perimetro

vector<vector<int>> listAdj;
vector<bool> visited;
map<int, ii> cowPos;
// x_min, y_min, x_max, y_max
vector<tuple<int, int, int, int>> mn;

void dfs(int i, int idx){
    visited[i] = true;

    int curr_x = cowPos[i].first;
    int curr_y = cowPos[i].second;

    get<0>(mn[idx]) = min(get<0>(mn[idx]), curr_x);
    get<1>(mn[idx]) = min(get<1>(mn[idx]), curr_y);
    get<2>(mn[idx]) = max(get<2>(mn[idx]), curr_x);
    get<3>(mn[idx]) = max(get<3>(mn[idx]), curr_y);

    for(auto adj : listAdj[i]){
        if(!visited[adj]) dfs(adj, idx);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    listAdj.assign(n, vector<int>());
    visited.assign(n, false);

    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        cowPos[i] = {x, y};
    }

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }

    int c_idx = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            mn.push_back({INF, INF, -1, -1});
            dfs(i, c_idx);
            c_idx++;
        }
    }

    int ans = INF;
    for(auto [xmin, ymin, xmax, ymax] : mn){
        if(xmin == xmax && ymin == ymax) ans = 0; // apenas um vertice na componente
        else{
            int perimeter = 2*(xmax - xmin) + 2*(ymax - ymin);
            ans = min(ans, perimeter);
        }
    }

    cout << ans << "\n";
}

signed main(){
	setIO("fenceplan");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
