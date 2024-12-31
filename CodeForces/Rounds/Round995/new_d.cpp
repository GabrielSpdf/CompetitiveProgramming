#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int binary_search_range(const std::vector<ll>& array, int a, int min, int max) {
    int top = array.size() - 1;
    int bot = 0;
    while (top >= bot) {
        int p = std::floor((top + bot) / 2.0);
        int sum = a + array[p];
        if (sum < min) {
            bot = p + 1;
        } else if (sum > max) {
            top = p - 1;
        } else {
            return array[p];
        }
    }
    return -1;
}

std::pair<int, int> first_sum_in_range(const std::vector<ll>& array, int min, int max) {
    for (const auto& a : array) {
        int b = binary_search_range(array, a, min, max);
        if (b != -1) {
            return {a, b};
        }
    }
    return {-1, -1};
}

ll inf, sup;

void solve(){
	map<ll, vector<ll>> mapa;

	ll n, x, y;
	cin >> n >> x >> y;
	
	vector<ll> v(n);
	set<ll> s;
	ll sum=0;
	for(int i=0; i<n; i++){
		cin >> v[i];
		sum+=v[i];
		/* s.insert(v[i]); */
		/* mapa[v[i]].push_back(i); */
	}

	inf = sum-x;
	sup = sum-y;

    std::pair<int, int> result = first_sum_in_range(v, inf, sup);
    
    if (result.first != -1 && result.second != -1) {
        std::cout << "[" << result.first << ", " << result.second << "]" << std::endl;
    } else {
        std::cout << "No pair found." << std::endl;
    }


	/* if(sum<=x){ */
	/* 	cout << 0 << "\n"; */
	/* } */
	/* else if(sum>y){ */

	/* } */
	/* else{ */
	/* 	sup = inf; */
	/* } */

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
