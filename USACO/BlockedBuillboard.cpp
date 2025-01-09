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

struct Rect{
	int x1, y1, x2, y2;
	int	area(){
		return (y2-y1)*(x2-x1);
	}
};

int intersect(Rect p, Rect q){
	int l1 = max(min(p.x2, q.x2)-max(p.x1, q.x1), 0);
	int l2 = max(min(p.y2, q.y2)-max(p.y1, q.y1), 0);

	return l1*l2;
}

void solve(){
	Rect a, b, t;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

	int fll_area = a.area() + b.area();
	int ov1 = intersect(a, t);
	int ov2 = intersect(b, t);
	
	cout << fll_area - (ov1+ov2) << "\n";
}

int main(){
	setIO("billboard");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
