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
	int num=362880;
	for(int i=1; i<=9; i+=2){
		if(num%i==0) cout << i << " ";
	}
	cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
