#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(n) for(int i=0; i<(n); i++)
#define FORJ(n) for(int j=0; j<(n); j++)
#define FORK(n) for(int k=0; k<(n); k++)
#define tvi(v) FORI((v).size()) cerr << (v)[i] << " "; cerr << "\n"
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI((v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI((v).size()) { FORJ((v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

struct Rect{
	int x1, y1, x2, y2;
};

void solve(){
	int n, m;
	cin >> n >> m;

	Rect a;
	a.x1=0, a.y1=0, a.x2=m, a.y2=m;

	vector<Rect> rec;
	FORI(n){
		int x1, y1;
		cin >> x1 >> y1;
		a.x1+=x1, a.y1+=y1, a.x2+=x1, a.y2+=y1;
		rec.push_back(a);
	}

	int ans=2*m;
	for(int i=1; i<n; i++){
		int width1 = rec[i-1].x2 - rec[i-1].x1;
		int height1 = rec[i-1].y2 - rec[i-1].y1;

		int width2 = rec[i].x2 - rec[i].x1;
		int height2 = rec[i].y2 - rec[i].y1;
		
		int inwidht = max(min(rec[i-1].x2, rec[i].x2)-max(rec[i-1].x1, rec[i].x1), 0LL);
		int inheight = max(min(rec[i-1].y2, rec[i].y2)-max(rec[i-1].y1, rec[i].y1), 0LL);
		ans+=(width1-inwidht);
		ans+=(height1-inheight);
	}

	cout << 2*ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
