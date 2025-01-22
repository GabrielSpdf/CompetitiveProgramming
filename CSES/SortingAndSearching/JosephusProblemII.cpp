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
#define tvvi(v) FORI(0, (v).size()) { FORJ((v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

vi fenwicks;

void fupdate(int pos, int val){
	for(; pos<(int)fenwicks.size(); pos+=(pos & -pos)) fenwicks[pos] += val;
}

int fsum(int pos){
	int s=0;
	for(; pos>0; pos-= (pos&-pos)) s+= fenwicks[pos];
	return s;
}

int fselect(int target){
	int pos=0;
	int bit_mask = 1 << 20;
	while(bit_mask > 0){
		int nxt = pos+bit_mask;
		if(nxt<(int)fenwicks.size() && fenwicks[nxt]<target){
			target -= fenwicks[nxt];
			pos = nxt;
		}
		bit_mask >>=1 ;
	}
	return pos+1;
}

void solve(){
	int n, k;
	cin >> n >> k;

	fenwicks.assign(n+1, 0LL);
	FORI(1, n+1) fupdate(i, 1);

	int alive = n;
	int offset = 1;

	FORI(0, n){
		offset = (offset+k-1)%alive;
		offset++;

		int pos=fselect(offset);

		cout << pos << " ";

		fupdate(pos, -1);
		--alive;
	}
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
