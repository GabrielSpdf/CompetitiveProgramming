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
	vi tm(3), now(3);

	cin >> tm[0] >> now[0];
	cin >> tm[1] >> now[1];
	cin >> tm[2] >> now[2];
	
	int temp=0;
	for(int i=0; i<100; i++){
		int cur=i%3, next=(i+1)%3;
		temp = min(tm[next]-now[next], now[cur]);

		now[next]+=temp;
		now[cur]-=temp;
	}

	cout << now[0] << "\n";
	cout << now[1] << "\n";
	cout << now[2] << "\n";
}

int main(){
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
