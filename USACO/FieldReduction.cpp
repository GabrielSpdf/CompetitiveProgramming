// Unsolved yet

#include <bits/stdc++.h>
#include <climits>
#include <cmath>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

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

double dist(double x1, double y1, double x2, double y2){
	double dx = x2-x1;
	double dy = y2-y1;

	return hypot(dx, dy);
}

struct t3{
	double dist;
	ll x, y; 
};

void solve(){
	int n;
	cin >> n;
	
	double mx=0, my=0;
	vpll points;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
		mx += x;
		my += y;
	}
	mx/=n; my/=n;
	
	vector<t3> ans;
	for(int i=0; i<n; i++){
		ans.push_back({dist(mx, my, points[i].first, points[i].second), points[i].first, points[i].second});
	}

	sort(ans.begin(), ans.end(), [](const t3&a, const t3&b){
		return a.dist < b.dist;
	});

	ll x_mx, x_mn, y_mx, y_mn;
	x_mx=y_mx=LLONG_MIN, x_mn=y_mn=LLONG_MAX;
	for(int i=0; i<(n-3); i++){
		if(ans[i].x>x_mx) x_mx=ans[i].x;
		if(ans[i].y>y_mx) y_mx=ans[i].y;
		if(ans[i].x<x_mn) x_mn=ans[i].x;
		if(ans[i].y<y_mn) y_mn=ans[i].y;
	}

	cout << (x_mx-x_mn)*(y_mx-y_mn) << "\n";
}

int main(){
	/* setIO("reduce"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
