#include <bits/stdc++.h>
#include <climits>

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
		return((x2-x1)*(y2-y1));
	}
};

void solve(){
	ll W, H;
	cin >> W >> H;

	Rec t;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

	ll w, h;
	cin >> w >> h;
	
	ll width = t.x2 - t.x1;
	ll length = t.y2 - t.y1;
	if(width + w > W && length + h > H){ cout << -1 << "\n"; return; }

	ll dist = LLONG_MAX;
	if(width + w <= W){
		dist = min(dist, max((w + t.x2 - W), 0LL));
		dist = min(dist, max((w - t.x1), 0LL));
	}
	if(length + h <= H){
		dist = min(dist, max((h + t.y2 - H), 0LL));
		dist = min(dist, max((h - t.y1), 0LL));
	}
	
	if(dist==LONG_LONG_MAX) dist=0;
	
	cout << dist << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
