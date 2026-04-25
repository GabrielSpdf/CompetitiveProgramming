#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi visited;
vector<vii> listAdj;
map<ii, int> ans;
int edge;

void dfs(int idx){
	if(visited[idx]==true) return;

	visited[idx] = true;

	int next=-1;
	for(auto adj: listAdj[idx]){
		if(visited[adj.first]==true){
			if(adj.second == 5) edge=2;
			else edge=5;
		}
		else{
			next=adj.first;
			adj.second=edge;
			ans[make_pair(idx, next)] = edge;
		}
	}

	cout << "next: " << next << "\n";
	
	if(next!=-1){
		dfs(next);
	}
}

void solve(){
	int n;
	cin >> n;

	visited.clear();
	listAdj.clear();
	ans.clear();
	edge = 2;

	visited = vi(n+1);
	listAdj = vector<vii>(n+1);
	vii order;

	for(int i=0; i<n-1; i++){
		int inp1, inp2;
		cin >> inp1 >> inp2;
		order.push_back(make_pair(inp1, inp2));

		listAdj[inp1].emplace_back(make_pair(inp2, 0));
		listAdj[inp2].emplace_back(make_pair(inp1, 0));
	}
	
	int start=-1;
	for(int i=0; i<n; i++){
		if(i!=1){
			if(listAdj[i].size()>2){
				cout << -1 << "\n";
				return;
			}
		}	

		if(listAdj[i].size()==1){
			start = i;
		}
	}

	if(start!=-1){
		dfs(start);
		for(auto value : order){
			cout << max(ans[make_pair(value.first, value.second)], ans[make_pair(value.second, value.first)]) << " ";
		}
		cout << "\n";
	}
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
