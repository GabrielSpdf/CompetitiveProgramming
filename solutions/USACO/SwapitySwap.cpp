#include <bits/stdc++.h>

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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vvi position;
vi bg;
vi cur;

void fill(int p1, int p2){
	if(p1>=p2) return;

	int aux=cur[p1];
	cur[p1] = cur[p2];
	cur[p2] = aux;

	fill(p1+1, p2-1);
}

void ad(){
	for(int i=0; i<position.size(); i++) position[i].push_back(cur[i]);
}

void solve(){
	int n, k, a1, a2, b1, b2;
	cin >> n >> k;
	cin >> a1 >> a2; a1--; a2--;
	cin >> b1 >> b2; b1--; b2--;

	position = vvi(n);
	cur = vi(n);
	bg = vi(n);

	iota(cur.begin(), cur.end(), 1);
	iota(bg.begin(), bg.end(), 1);
	
	ad();
	fill(a1, a2);	
	
	bool swt=false;

	while(cur != bg){
		ad();
		if(!swt){ fill(b1, b2); swt=true; }
		else{ fill(a1, a2); swt=false; }
	}

	/* for(int i=0; i<position.size(); i++){ */
	/* 	for(int j=0; j<position[i].size(); j++){ */
	/* 		cout << position[i][j] << " "; */
	/* 	} */	
	/* 	cout << "\n"; */
	/* } */
	/* cout << "****\n"; */

	for(int i=0; i<position.size(); i++){
		cout << position[i][2*k % (position[i].size())] << "\n";
	}
}

int main(){
	setIO("swap");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
