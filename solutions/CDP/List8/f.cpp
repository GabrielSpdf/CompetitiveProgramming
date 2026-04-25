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

void solve(){
	int n; cin >> n;
	string a, b; cin >> a >> b;
	
	int qtd_ans = 0;
	int qtd_1 = 0, qtd_2 = 0;
	int same=0, diff=0;
	int d01=0, d10=0;
	FORI(0, a.size()){
		b[i]=='0' && a[i]=='1'? d01++ : (b[i]=='1' && a[i]=='0'? d10++ : 1);
		b[i] == a[i]? same++ : diff++;
		b[i] == '1'? qtd_ans++ : qtd_ans=qtd_ans;
		a[i] == '1'? qtd_1++ : qtd_1=qtd_1;
	}
	qtd_2 = qtd_1 - (qtd_1-1) + (n-qtd_1);
	
	if(qtd_ans != qtd_1 && qtd_ans != qtd_2){
		cout << -1 << "\n";
		return;
	}

	cout << (max(d01, d10)%2==0? max(d01, d10)*2 : max(d10, d01)) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
