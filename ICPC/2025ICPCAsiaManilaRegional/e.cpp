#include <bits/stdc++.h>

using namespace std;

#define int long long

// . -> vazio
// x -> obstaculo
// S -> inicio
// D -> destino

const vector<pair<int, int>> deltas = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
int memo[100][100][100][100];
vector<string> a, b;
using ii = pair<int, int>;
int r, c;
const int MX = LLONG_MAX;

bool outOfBounds(ii pos, bool isA){
    if(pos.first > r-1) return true;
    if(pos.first < 0) return true;
    if(pos.second > c-1) return true;
    if(pos.second < 0) return true;
    vector<string>& m = (isA ? a : b);
    if (m[pos.first][pos.second] == 'X') return true;
    return false;
}

void explore(ii posA, ii posB) {
    deque<pair<ii, ii>> queue = {{posA, posB}};
    while (!queue.empty()) {
        auto [posA, posB] = queue.front();
        queue.pop_front();
        int currentDist = memo[posA.first][posA.second][posB.first][posB.second];
        for (auto [di, dj] : deltas) {
            ii newA = {posA.first + di, posA.second + dj};
            if (outOfBounds(newA, true)) continue;
            ii newB = {posB.first + di, posB.second + dj};
            if (outOfBounds(newB, false)) newB = posB;

            int &newDist = memo[newA.first][newA.second][newB.first][newB.second];
            if (newDist == MX) {
                newDist = currentDist + 1;
                queue.emplace_back(newA, newB);
            }
        }
    }
}

void solve(){
    cin >> r >> c;
    a = vector<string>(r);
    b = vector<string>(r);
    pair<int, int> startA, startB, endB;
    for (int i = 0; i < r; i++) {
        cin >> a[i];
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'S') {
                startA = {i, j};
            }
        }
    }
    for (int i = 0; i < r; i++) {
        cin >> b[i];
        for (int j = 0; j < c; j++) {
            if (b[i][j] == 'S') {
                startB = {i, j};
            }
            if (b[i][j] == 'D') {
                endB = {i, j};
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int p = 0; p < r; p++) {
                for (int q = 0; q < c; q++) {
                    memo[i][j][p][q] = MX;
                }
            }
        }
    }
    memo[startA.first][startA.second][startB.first][startB.second] = 0;
    explore(startA, startB);
    int ans = MX;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = min(ans, memo[i][j][endB.first][endB.second]);
        }
    }

    if(ans == MX) ans = -1;

    cout << ans << "\n";
}

signed main(){
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}