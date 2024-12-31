#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

struct Mys{
	string s;
	int mn, mx;
};

void solve(){
	int n;
	cin >> n;	
	
	vector<Mys> order;
	for(int i=0; i<n; i++){
		Mys p;
		cin >> p.s >> p.mn >> p.mx;
		order.push_back(p);
	}

	int endmn=-100000, endmx=100000;
	for(auto [s, mn, mx] : order){
		if(s=="none"){
			endmn=max(mn, endmn);
			endmx=min(mx, endmx);
		}
		if(s=="off"){
			endmn=max(0, endmn-mx);
			endmx=max(0, endmx-mn);
		}
		if(s=="on"){
			endmn+=mn;
			endmx+=mx;
		}
	}
	
	reverse(order.begin(), order.end());
	int inimn=endmn, inimx=endmx;
	for(auto [s, mn, mx] : order){
		if(s=="none"){
			inimn=max(mn, inimn);
			inimx=min(mx, inimx);
		}
		if(s=="on"){
			inimn=max(0, inimn-mx);
			inimx=max(0, inimx-mn);
		}
		if(s=="off"){
			inimn+=mn;
			inimx+=mx;
		}
	}
	
	cout << inimn << " " << inimx << "\n";
	cout << endmn << " " << endmx << "\n";

}

int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
