#include <bits/stdc++.h>

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

vector<char> v = {'R', 'D', 'L', 'U'};
vbl visited;

vvi sets(8);
int dir_change = 0;

void ic(int& idx, bool right){
	// Ir para proxima direcao
	int n=4;
	if(right) idx = (idx+1)%n;
	else idx = ((idx-1)%n+n)%n;
}

void t_m(int set_idx, int idx, int i, int j, int n, vvi& m, bool right){
	/*
	 * set_idx: em qual conjunto estamos
	 * idx: indice da direcao
	 * i: linha
	 * j: coluna
	 * n: tamanho da linha e coluna
	 * m: matriz
	 * right: pega a direcao da direita ou da esquerda
	 * */
	if(dir_change==4) return; // se chegou no final vai tentar os 4 caminhos

	if(!visited[i*n+j]) sets[set_idx].pb(m[i][j]);
	visited[i*n+j] = true;

	if(v[idx]=='R'){
		if(j==n-1 || visited[i*n+j+1]==true){ ic(idx, right); dir_change++; }
		else{ j++; dir_change=0; }
	}
	else if(v[idx]=='D'){
		if(i==n-1 || visited[(i+1)*n+j]==true){ ic(idx, right); dir_change++; }
		else { i++; dir_change = 0; }
	}
	else if(v[idx]=='L'){
		if(j==0 || visited[i*n+j-1]==true) {ic(idx, right); dir_change++; }
		else { j--; dir_change = 0; }
	}
	else{ // U
		if(i==0 || visited[(i-1)*n+j]==true) {ic(idx, right); dir_change++; }
		else { i--; dir_change = 0; }
	}
	
	t_m(set_idx, idx, i, j, n, m, right);
}

void solve(){
	int n; cin >> n;
	vvi m(n, vi(n));
	sets.clear();

	visited = vbl(n*n, 0);
	FORI(0, n){
		FORJ(0, n){
			cin >> m[i][j];
		}
	}
	
	int idx_set=0;
	FORI(0, 2){
		dir_change =0;
		fill(all(visited), false);
		t_m(idx_set, i, 0, 0, n, m, i);
		idx_set++;
	}
	FORI(0, 2){
		dir_change =0;
		fill(all(visited), false);
		t_m(idx_set, i, n-1, n-1, n, m, i); 
		idx_set++;
	}
	FORI(0, 2){
		dir_change =0;
		fill(all(visited), false);
		t_m(idx_set, i, n-1, 0, n, m, i);
		idx_set++;
	}
	FORI(0, 2){
		dir_change =0;
		fill(all(visited), false);
		t_m(idx_set, i, 0, n-1, n, m, i);
		idx_set++;
	}

	int best = 0;
	FORJ(0, 8){
		vi ps(n*n+1);
		vi mps(n*n+1);
		ps[0]=0;

		FORI(1, sets[j].size()+1){
			ps[i] = ps[i-1] + sets[j][i-1];	
		}
		
		mps[mps.size()-1]=ps[ps.size()-1];
		for(int i=mps.size()-2; i>=0; i--){
			mps[i]=max(ps[i], mps[i+1]);
		}

		FORI(0, mps.size()){
			best = max(best, mps[i]-ps[i]);
		}

		/* cout << "best: " << best << "\n"; */
	}
	cout << best << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
