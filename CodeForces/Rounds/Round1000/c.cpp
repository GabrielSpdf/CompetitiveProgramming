#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <csignal>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI(0, (v).size()) cerr << (v)[i] << " "; cerr << "\n";
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI(0, (v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI(0, (v).size()) { FORJ(0, (v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 
#define rall(v) (v).rbegin(), (v).rend() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

vvi graph;

int fnd(vi cand, int prev, vi deg){
	int min_sum=LLONG_MAX;
	int endwho;

	for(auto v: cand){
		int sum=0;
		for(auto u: graph[v]){
			if(u!=prev) sum+=deg[u];
		}
		if(sum<min_sum){
			min_sum=sum;
			endwho=v;
		}
	}
	
	/* cerr << "endwho: " << endwho << "\n"; */
	if(prev!=-1) return deg[endwho]-1;
	else return endwho;
}

void solve(){
	int n;
	cin >> n;
	
	graph.clear();
	graph = vvi(n);
	FORI(0, n-1){
		int inp1, inp2;
		cin >> inp1 >> inp2; --inp1; --inp2;

		graph[inp1].pb(inp2);
		graph[inp2].pb(inp1);
	}
	
	// Caso base
	if(n<=2){
		cout << 0 << "\n";
		return;
	}
	
	vi deg(n, 0);
	int mx_deg=0;
	// Armazenar maior grau
	FORI(0, n){
		deg[i]=graph[i].size();
		if(deg[i]>mx_deg) mx_deg=deg[i];
	}

	vi cand_first;
	// Armazena os candidatos a serem retirados
	FORI(0, n){ if(deg[i]==mx_deg) cand_first.pb(i); }
	int ans=0;

	int who=fnd(cand_first, -1, deg);
	ans+=deg[who];
	
	vi adj;
	
	FORI(0, graph[who].size()){
		deg[graph[who][i]]--;
	}
	
	mx_deg=0;
	FORI(0, n){
		if(i==who) continue;
		if(deg[i]>mx_deg) mx_deg=deg[i];
	}
	
	/* cerr << "mx_deg: " << mx_deg << "\n"; */
	vi cand_second;
	FORI(0, n){ if(deg[i]==mx_deg) cand_second.pb(i); }
	
	ans+=fnd(cand_second, who, deg);

	cout << max(ans, 0LL) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
