#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int n, m, qtd_layers=0, ans=0;
	cin >> n >> m;
	string s;
	qtd_layers=min(n, m)/2;
	vector<string> map;
	vector<vector<int>> layers(qtd_layers);

	for(int i=0; i<n; i++){
		cin >> s;
		map.push_back(s);
	}

	for(int layer=0; layer<qtd_layers; layer++){
		int st_i1=0+layer, st_i2=n-layer-1;
		int st_j1=0+layer, st_j2=m-layer-1;

		for(int j=st_j1; j<st_j2; j++){
			layers[layer].emplace_back(map[st_i1][j]-'0');
		}

		for(int i=st_i1; i<st_i2; i++){
			layers[layer].emplace_back(map[i][st_j2]-'0');
		}

		for(int j=st_j2; j>st_j1; j--){
			layers[layer].emplace_back(map[st_i2][j]-'0');
		}

		for(int i=st_i2; i>st_i1; i--){
			layers[layer].emplace_back(map[i][st_j1]-'0');
		}
	}

	for(int i=0; i<qtd_layers; i++){
		int last_pos=(int)layers[i].size();
		for(int j=0; j<last_pos-3; j++)
			if(layers[i][j]==1 && layers[i][j+1]==5 && layers[i][j+2]==4 && layers[i][j+3]==3) ans++;

		if(layers[i][last_pos-3]==1 && layers[i][last_pos-2]==5 && layers[i][last_pos-1]==4 && layers[i][0]==3) ans++;
		if(layers[i][last_pos-2]==1 && layers[i][last_pos-1]==5 && layers[i][0]==4 && layers[i][1]==3) ans++;
		if(layers[i][last_pos-1]==1 && layers[i][0]==5 && layers[i][1]==4 && layers[i][2]==3) ans++;
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
