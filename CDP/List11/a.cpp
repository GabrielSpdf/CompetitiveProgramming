#include <bits/stdc++.h>
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

int fact(int n){
	int result = 1;
	for(int i=2; i<=n; ++i)
		result *= i;
	return result;
}

int comb(int ing, int plus){
	int result=0;
	for(int i=0+plus; i<=ing; i++){
		int comb = fact(ing) / (fact(i) * fact(ing-i));
		/* cout << "comb: " << comb << "\n"; */
		result += comb;
	}
	return result;
}

void solve(){
	int n, m, p, s;
	cin >> n >> m >> p >> s;

	vii und(m);
	for(int i=0; i<m; i++){
		int inp1, inp2; cin >> inp1 >> inp2;
		if(inp1>inp2){
			und[i].first = inp2;
			und[i].second = inp1;
		}
		else{
			und[i].first = inp1-1;
			und[i].second = inp2-1;
		}
	}

	// calculo de todas as formas possiveis
	int ways=0;
	int ing = n-p-s;
	int ing_ways=0;
	/* cout << "ing: " << ing << "\n"; */
	ing_ways = comb(ing, 0);
	ways = p*s*ing_ways;

	/* cout << ways << "\n"; */
	cerr << "total: " << ways << "\n";
	// calculo das formas que nao queremos
	FORI(0, (int)und.size()){
		int und_ways = 0;

		if(und[i].first < p+s && und[i].second < p+s){ // B S 
			cerr << "batata\n";
			ways -= ing_ways;
		}
		else if(und[i].first < p+s && und[i].first < p){
			cerr << "pao\n";
			cerr << "removed: " << comb(ing-1, 0) << "\n";
			ways -= comb(ing-1, 0)*s;
		}
		else if(und[i].second < p+s){
			cerr << "arroz\n";
			cerr << "removed: " << comb(ing-1, 0) << "\n";
			ways -= comb(ing-1, 0)*p;
		}
		else{
			cerr << "feijao\n";
			cerr << "removed: " << p*s*comb(ing-1, 2) << "\n";
			ways -= p*s*comb(ing-1, 2);
		}
	}

	cout << ways << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
