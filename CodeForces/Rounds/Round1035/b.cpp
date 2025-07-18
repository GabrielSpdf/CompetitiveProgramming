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

double dist(int px, int py, int qx, int qy){
	return sqrtl(((px-qx)*(px-qx))+((py-qy)*(py-qy)));
}

bool verify(vector<double> v){
	bool ans = true;
	for(int i=0; i<(int)v.size(); i++){
		double sum=0, dif=0;
		for(int j=0; j<(int)v.size(); j++){
			if(i==j) dif=v[i];
			else{
				sum+=v[j];
			}
		}
		// cout << "dif: " << dif << "\n";
		// cout << "sum: " << sum << "\n";
		if(dif>sum){
			return false;
		}
	}
	return ans;
}

void solve(){
	int n, px, py, qx, qy;
	cin >> n >> px >> py >> qx >> qy;

	vector<double> v(n);
	for(auto &a: v) cin >> a;

	v.push_back(dist(px, py, qx, qy));
	bool ans = verify(v);

	cout << (ans==true? "Yes" : "No") << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
