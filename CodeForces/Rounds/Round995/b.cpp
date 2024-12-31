#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	ll n, a, b, c;
	cin >> n >> a >> b >> c;

	vector<ll> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	ll sum=a+b+c;
	ll rest=n%sum;
	ll copy_rest = n/sum;
	
	int exc=0;
	for(int i=1; i<=3; i++){
		if(rest<=0) break;
		exc++;
		rest -= arr[i-1];
	}
	
	cout << 3*copy_rest + exc << "\n";


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
