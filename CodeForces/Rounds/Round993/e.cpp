#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll expbin(ll a, ll exp){
	if(exp == 0) return 1;
	if(exp%2) return(a * expbin(a, exp-1));

	ll b = expbin(a, exp/2);
	return b*b;
}

ll logk(int x, int k){ //pegar o logk de um numero qualquer
	int ans=0;
	while(x>0){
		x/=k;
		ans++;
	}
	return ans;
}

void solve(){
	int k, l1, r1, l2, r2;

	cin >> k >> l1 >> r1 >> l2 >> r2;
	
	int ans=0, n=0, n_max=logk(INT32_MAX, k);
	while(true){
		int expk = expbin(k, n);
		
		int l3 = (l2+expk-1)/expk;
		int r3 = r2/expk;

		int l4 = max(l1, l3);	
		int r4 = min(r1, r3);	

		int seg_leng = max((r4-l4+1), 0);

		ans += seg_leng;
		n++;

		if(n==n_max) break;
	}

	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
