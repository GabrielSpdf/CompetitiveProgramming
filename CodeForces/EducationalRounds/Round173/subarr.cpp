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
	int n;
	cin >> n;
	vi v(n);
	for(auto &a: v) cin >> a;

	int maior=0, menor=0, cur_max=0, cur_min=0, cur=0, past=0;

	for(int i=0; i<v.size(); i++){
		cur+=v[i];
		if(cur>past){ // v[i]==+1
			cur_max+=v[i];
			cur_min=min(0, cur_min+v[i]);
		}
		else{ // v[i]==-1
			cur_max=max(0, cur_max+v[i]);
			cur_min+=v[i];
		}
		if(cur_min<menor) menor=cur_min;
		if(cur_max>maior) maior=cur_max;
		past=cur;
	}

	cout << "Max subarray sum: " << maior << "\n";
	cout << "Min subarray sum: " << menor << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
