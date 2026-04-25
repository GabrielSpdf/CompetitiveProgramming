#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m;
vector<vector<char>> mtx;
vector<vector<int>> depth;
deque<ii> q;

// dr, dc, mov
tuple<int, int, char> moves[]{{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};

bool is_possible(ii pos){
    auto [r, c] = pos;
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

int bfs(ii src){
    int qtt = 1;
    q.emplace_back(src);

    while(!q.empty()){
        ii curr = q.back();
        q.pop_back();
        qtt = max(qtt, depth[curr.first][curr.second]);

        for(auto [dr, dc, mov] : moves){
            int new_r = curr.first + dr;
            int new_c = curr.second + dc;

            if(is_possible({new_r, new_c})){
                if(depth[new_r][new_c] != 0) continue;
                if(mtx[new_r][new_c] == '.') continue;
                if(mtx[new_r][new_c] == mtx[curr.first][curr.second]){
                    depth[new_r][new_c] = depth[curr.first][curr.second];
                    q.emplace_back(new_r, new_c);
                }
                else{
                    depth[new_r][new_c] = depth[curr.first][curr.second] + 1;
                    q.emplace_front(new_r, new_c);
                }
            }
        }
    }

    return qtt;
}

void solve(){
    // int n, m;
    cin >> n >> m;

    vector<ii> cands;
    mtx.assign(n, vector<char>(m));
    depth.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mtx[i][j];
        }
    }

    depth[0][0] = 1;
    int ans = bfs({0, 0});
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
