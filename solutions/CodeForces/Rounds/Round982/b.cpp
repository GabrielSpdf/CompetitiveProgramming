#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int find(int index, vi& v, int n){
	int n_min=0, n_max=0, my_num=v[index];

	for(int i=index; i<n; i++){
		if(my_num<v[i]) n_max++;
	}

	for(int i=index; i>=0; i--){
		if(my_num!=v[i]) n_min++;
	}

	return n_max+n_min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, min=INT_MAX;
		cin >> n;
		vi v(n);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		
		for(int i=0; i<n; i++){
			int find_num=find(i, v, n);
			if(find_num<min) min=find_num;
		}

		cout << min << "\n";
	}


    return 0;
}

