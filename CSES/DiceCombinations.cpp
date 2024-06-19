#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const long long MAX = 10e6;
const long long MODULO = (INF+7);
const double EPS = 1e-9;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	ll n, sum=0;
	cin >> n;
	vector<ll> memo(MAX);

	memo[0]=1;

	for(ll i=1, j=0; i<MAX; i++){
		sum+=(memo[i-1]%MODULO);
		if(i>6) { sum-=memo[j]; j++; }

		if(i<=5) memo[i]=sum+1;
		else memo[i]=(sum%MODULO);
	}


	cout << memo[n-1] << "\n";


	




    return 0;
}
