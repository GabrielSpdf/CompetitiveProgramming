#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1e9;

vector<vector<char>> mtx;
vector<vector<int>> time_m, time_a;
vector<vector<char>> path;

queue<ii> q_m, q_a;

// U, R, D, L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<char> moves = {'U', 'R', 'D', 'L'};

bool is_out_of_bound(int i, int j){
    return (mtx.size() == 0 || i < 0 || i >= mtx.size() || j < 0 || j >= mtx[0].size() || mtx[i][j] == '#');
}

ii bfs_a(){
    while(!q_a.empty()){
        ii curr = q_a.front();
        q_a.pop();

        if(curr.first == 0 || curr.second == 0 || curr.first == mtx.size()-1 || curr.second == mtx[0].size()-1)
                return curr;

        for(int k=0; k<4; k++){
            int fst = curr.first + dx[k];
            int snd = curr.second + dy[k];

            if(is_out_of_bound(fst, snd) || time_a[fst][snd]!=INF) continue;

            if(time_a[curr.first][curr.second] + 1 < time_m[fst][snd]){
                time_a[fst][snd] = time_a[curr.first][curr.second] + 1;
                path[fst][snd] = moves[k];
                q_a.push({fst, snd});

                if(fst == 0 || snd == 0 || fst == mtx.size()-1 || snd == mtx[0].size()-1){
                    return {fst, snd};
                }
            }
        }
    }
    return {-1, -1};
}

void bfs_m(){
    while(!q_m.empty()){
        ii curr = q_m.front();
        q_m.pop();

        for(int k=0; k<4; k++){
            int fst = curr.first + dx[k];
            int snd = curr.second + dy[k];

            if(is_out_of_bound(fst, snd) || time_m[fst][snd]!=INF) continue;

            time_m[fst][snd] = time_m[curr.first][curr.second] + 1;
            q_m.push({fst, snd});
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    mtx.assign(n, vector<char>(m));
    time_m.assign(n, vector<int>(m, INF));
    time_a.assign(n, vector<int>(m, INF));
    path.assign(n, vector<char>(m, '$'));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mtx[i][j];
            if(mtx[i][j]=='A'){
                q_a.emplace(i, j);
                time_a[i][j] = 0;
            }
            else if(mtx[i][j]=='M'){
                q_m.emplace(i, j);
                time_m[i][j] = 0;
            }
        }
    }

    bfs_m();
    ii st = bfs_a();

    if(st.first == -1 && st.second == -1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<char> track;
    char curr = path[st.first][st.second];
    while(curr != '$'){
        track.emplace_back(curr);

        if(curr == 'U') st.first++;
        if(curr == 'D') st.first--;
        if(curr == 'L') st.second++;
        if(curr == 'R') st.second--;
        curr = path[st.first][st.second];
    }
    reverse(track.begin(), track.end());

    int sz = (int)track.size();
    cout << sz << "\n";
    for(int i=0; i<sz; i++){
        cout << track[i];
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
