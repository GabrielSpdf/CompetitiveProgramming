#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char move_char[] = {'U', 'D', 'L', 'R'};

int bfs(vvc& mtx, queue<pair<int, int>>& q, vvb& visited, int i, int j, vector<vector<int>>& dist, vector<vector<int>>& from_move){
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while(!q.empty()){
        int vf = q.front().first;
        int vs = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int fst = vf + dx[k];
            int snd = vs + dy[k];

            if(fst < 0 || snd < 0 || mtx.size()<=0 || fst >= mtx.size() || snd >= mtx[0].size() || mtx[fst][snd] == '#'){
                continue;
            }

            if(!visited[fst][snd]){
                visited[fst][snd] = true;
                dist[fst][snd] = dist[vf][vs] + 1;
                from_move[fst][snd] = k;
                q.push(make_pair(fst, snd));

                if(mtx[fst][snd]=='B'){
                    return dist[fst][snd];
                }
            }
        }
    }
    return -1;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vvc mtx(n, vector<char>(m));

    pair<int, int> st;
    pair<int, int> end;
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin >> mtx[i][j];
            if(mtx[i][j]=='A'){
                st = make_pair(i, j);
            }
            else if(mtx[i][j]=='B'){
                end = make_pair(i, j);
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m));
    queue<pair<int, int>> q;
    vvb visited(n, vector<bool>(m, false));
    vector<vector<int>> from_move(n, vector<int>(m));

    int ans = bfs(mtx, q, visited, st.first, st.second, dist, from_move);

    if(ans == -1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << ans << "\n";

    string path = "";
    pair<int, int> curr = end;
    while(curr != st){
        int move = from_move[curr.first][curr.second];
        path += move_char[move];

        curr.first -= dx[move];
        curr.second -= dy[move];
    }

    reverse(path.begin(), path.end());
    cout << path << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
