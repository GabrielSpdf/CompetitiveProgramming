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
	int area(){
		return((x2-x1)*(y2-y1));
	}
};

void solve(){
	Rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	int init_area = a.area();
	int ovlpx = max(min(b.x2, a.x2)-max(b.x1, a.x1), 0);
	int ovlpy = max(min(b.y2, a.y2)-max(b.y1, a.y1), 0);
	int ovlp_area = ovlpx*ovlpy;

	cerr << ovlpx << " " << ovlpy << "\n";
	
	if(ovlpx<(a.x2-a.x1) && ovlpy<(a.y2-a.y1)) ovlp_area=0;
	if(b.x1>a.x1 && b.x2<a.x2) ovlp_area=0;
	if(b.y1>a.y1 && b.y2<a.y2) ovlp_area=0;
	cout << init_area-ovlp_area << "\n";
}

int main(){
	setIO("billboard");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
