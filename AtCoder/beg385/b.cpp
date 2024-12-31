#include <bits/stdc++.h>
#include <climits>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const long long MAX = LONG_LONG_MAX;
const long long MIN = LONG_LONG_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int h, w, x, y;
	cin >> h >> w >> x >> y;

	vector<string> map(h);
	for(int i=0; i<h; i++){
		/* for(int j=0; j<w; j++){ */
		cin >> map[i];
		/* } */
	}

	string t;
	cin >> t;
	
	ii current_pos = make_pair(x-1, y-1);
	vector<vector<bool>> visited(h, vector<bool>(w));
	int ans=0;

	for(int i=0; i<(int)t.size(); i++){
		/* cout << "current_pos: " << current_pos.first << " " << current_pos.second << " " << map[current_pos.first][current_pos.second] << "\n"; */
		ii pre_pos;
		if(t[i]=='U') pre_pos = make_pair(current_pos.first-1, current_pos.second);
		if(t[i]=='D') pre_pos = make_pair(current_pos.first+1, current_pos.second);
		if(t[i]=='L') pre_pos = make_pair(current_pos.first, current_pos.second-1);
		if(t[i]=='R') pre_pos = make_pair(current_pos.first, current_pos.second+1);
		
		/* cout << "mov: "<< t[i] << " "; */
		if(map[pre_pos.first][pre_pos.second] == '#') pre_pos = current_pos;
		else if(map[pre_pos.first][pre_pos.second] == '@'){
			current_pos = pre_pos;
			if(visited[current_pos.first][current_pos.second]==false){
				ans++;
				visited[current_pos.first][current_pos.second] = true;
			}
		}
		else if(map[pre_pos.first][pre_pos.second] == '.'){
			current_pos = pre_pos;
		}
	}

	cout << current_pos.first+1 << " " << current_pos.second+1 << " " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; */
	/* cin >> t; */
	/* while(t--){ */
	solve();
	/* } */

    return 0;
}

