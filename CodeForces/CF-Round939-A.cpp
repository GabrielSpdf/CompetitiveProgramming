//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	//2 1
	//3 5 a=[3,5]
	//5 n=5
	//1 2 3 4 5
	//1 2 x 4 x
	//1 2 4
	//1 2 count=2
		
	int t;
	cin >> t;
	while(t--){
		int k, q, count=0, menor;
		cin >> k >> q;

		vi vk(k), vq(q); 
		for(int i=0; i<k; i++){
			cin >> vk[i]; //a=[3,5]
		} 

		for(int i=0; i<q; i++){
			cin >> vq[i]; //1..n
		}

		menor = *min_element(vk.begin(), vk.end());

		for(int i=0; i<(int)vq.size(); i++){
			if(menor <= vq[i]) cout << menor-1 << " ";
			else cout << vq[i] << " ";
		}
		cout << "\n";
	}

    return 0;
}
