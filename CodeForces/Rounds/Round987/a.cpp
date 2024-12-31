#include <bits/stdc++.h>
#include <utility>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
	int n;
	cin >> n;
	vi v(n), rep(2300);
	for(auto &a: v){
		cin >> a;
		rep[a]++;
	}
	
	int mon, noo=0;
	for(int i=0; i<(int)rep.size(); i++){
		if(rep[i]>noo){ noo=rep[i]; mon=i; }
	}

	int lo, fo;
	bool flag=false;
	for(int i=0; i<n; i++){
		if(v[i]==mon){
			if(flag==false){ fo=i; flag=true; }
			lo=i;
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(i<lo && v[i]>mon){ ans++; v[i]=mon; } 
		if(i>lo && v[i]<mon){ ans++; v[i]=mon; }
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
