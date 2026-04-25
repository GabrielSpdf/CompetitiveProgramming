#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void solve(){
	int x, y;
	cin >> x >> y;

	int ft=1, dist=0;
	bool found=false, minus;

	if(x-y<0) minus=true;	
	else if(x-y>0) minus=false;
	else found=true;

	int cur=x;
	while(!found){
		ft*=-2;

		if((x-y<=0 && minus==false) || (x-y>=0 && minus==true)){
			found=true;
			dist+=abs(cur-y);
		}
		else{
			x=cur+ft;
			dist+=abs(x-cur);
		}
	}

	cout << dist << "\n";
}

int main(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
