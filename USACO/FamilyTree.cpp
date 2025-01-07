#include <bits/stdc++.h>
#include <cctype>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<bool> vbl;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

map<string, vector<string>> adj;
map<string, vector<string>> rv_adj;
map<string, vector<string>> fll_adj;
map<string, bool> visited;
bool related;
bool foundp2;
string ans;

void isrelated(string idx, string target){
	if(visited[idx]) return;
	visited[idx]=true;

	if(idx==target){ related=true; return; }

	for(auto nxt: fll_adj[idx]) isrelated(nxt, target);
}

int dfs(string idx, vector<string>& v, string target){
	if(visited[idx]) return 0;
	visited[idx]=true;

	if(idx==target){
		foundp2=true;
		return 0;
	}
	
	int deep=0;
	for(auto nxt: rv_adj[idx]){
		v.push_back(nxt);
		deep=dfs(nxt, v, target)+1;
	}

	return deep;
}

string solve1(string p1, string p2, vector<pair<string, string>>& inp_order){
	adj.clear();
	rv_adj.clear();
	fll_adj.clear();
	visited.clear();

	for(int i=0; i<(int)inp_order.size(); i++){
		string frst=inp_order[i].first;
		string scnd=inp_order[i].second;

		adj[frst].push_back(scnd);
		rv_adj[scnd].push_back(frst);

		fll_adj[frst].push_back(scnd);
		fll_adj[scnd].push_back(frst);
	}

	ans="";
	related=false;
	isrelated(p1, p2);
	visited.clear();
	if(related){
		ans="COUSINS";
		// verify if there is a direct desc
		vector<string> dir_desc;
		foundp2=false;
		int deep = dfs(p1, dir_desc, p2);
		if(foundp2){
			ans="";
			for(int j=0; j<(deep-2); j++) ans+="great-";
			if(deep>1) ans+="grand-";
			ans+="mother";
		}
		visited.clear();
		for(int i=0; i<(int)dir_desc.size(); i++){
			for(auto nxt: adj[dir_desc[i]]){
				visited[nxt]=true;
				if(nxt==p2){
					ans="";
					if(i==0) ans="SIBLINGS";
					else if(i==1) ans="aunt";
					else{
						for(int j=0; j<(i-1); j++) ans+="great-";
						ans+="aunt";
					}
				}
			}
		}
	}
	else{
		ans="NOT RELATED";
	}

	if(!isupper(ans[0])) ans= p2+" is the "+ans+" of "+p1+"\n";

	return ans;
}

void solve(){
	int n;
	string p1, p2;
	cin >> n >> p1 >> p2;
	
	vector<pair<string, string>> inp_order;
	for(int i=0; i<n; i++){
		string rl1, rl2;
		cin >> rl1 >> rl2;

		inp_order.emplace_back(make_pair(rl1, rl2));

		adj[rl1].push_back(rl2);
		rv_adj[rl2].push_back(rl1);
		fll_adj[rl1].push_back(rl2);
		fll_adj[rl2].push_back(rl1);
	}

	string ans1 = solve1(p1, p2, inp_order);
	string ans2 = solve1(p2, p1, inp_order);

	/* cout << ans1 << "\n"; */
	/* cout << ans2 << "\n"; */

	if(ans1 != "COUSINS") cout << ans1;
	else if(ans2 != "COUSINS") cout << ans2;
	else cout << ans1;
}

int main(){
	setIO("family");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
	solve();

    return 0;
}
