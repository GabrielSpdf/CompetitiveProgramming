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

struct Rec{
	ll x1, y1, x2, y2;
	ll area(){
		return ((x2-x1)*(y2-y1));
	}
};

ll intersect(Rec p, Rec q){
	ll width = max(min(p.x2, q.x2)-max(p.x1, q.x1), 0LL);
	ll length = max(min(p.y2, q.y2)-max(p.y1, q.y1), 0LL);

	return width*length;
}

void solve(){
	Rec w, b, c;
	cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
	
	ll ans = w.area();
	bool hasb=false, hasc=false;

	// Case 1
	if(intersect(w, b)){
		hasb=true;
		if(b.x2 > w.x2) b.x2 = w.x2;
		if(b.y1 < w.y1) b.y1 = w.y1; 
		if(b.x1 < w.x1) b.x1 = w.x1; 
		if(b.y2 > w.y2) b.y2 = w.y2;
		
		cerr << "ans: " << ans << "\n";
		ans -= intersect(w, b);
		cerr << "ans: " << ans << "\n";
	}
	if(intersect(w, c)){
		hasc=true;
		if(c.x2 > w.x2) c.x2 = w.x2;
		if(c.y1 < w.y1) c.y1 = w.y1; 
		if(c.x1 < w.x1) c.x1 = w.x1; 
		if(c.y2 > w.y2) c.y2 = w.y2;

		ans -= intersect(w, c);
	}
	if(hasb && hasc){
		ans+= intersect(b, c);
	}

	cerr << "hasb: " << hasb << "\n";
	cerr << "hasc: " << hasc << "\n";

	ans = max(ans, 0LL);

	if(ans>0) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
	solve();

    return 0;
}
