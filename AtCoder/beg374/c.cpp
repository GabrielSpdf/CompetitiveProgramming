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

void printTheArray(int arr[], int n, vector<string>& v)
{	
	string aux="";
    for (int i = 0; i < n; i++) {
		aux+=to_string(arr[i]);
    }
	v.push_back(aux);
}
 
void generateAllBinaryStrings(int n, int arr[], int i, vector<string>& v)
{
    if (i == n) {
        printTheArray(arr, n, v);
        return;
    }
 
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1, v);
 
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n;
	cin >> n;
	int arr[n];
	vector<string> comb;
	generateAllBinaryStrings(n, arr, 0, comb);

	vi v(n);
	for(auto &a : v) cin >> a;
	
	ll diff=INT_MAX, ans;
	for(int i=0; i<(int)comb.size(); i++){
		ll fire=0, water=0;

		for(int j=0; j<(int)comb[i].size(); j++){
			if(comb[i][j]=='0'){ fire+=v[j]; }
			else { water+=v[j]; }
		}

		if(abs(fire-water)<=diff){
			ans=max(fire, water);
			diff=abs(fire-water);
		}
	}

	cout << ans << "\n";


    return 0;
}

