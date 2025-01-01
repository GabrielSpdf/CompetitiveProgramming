#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n;
	cin >> n;

	vector<set<string>> vs(n); // todas as frases
	set<string> words;

	for(int i=0; i<n;  i++){
		int num;
		cin >> num;
		for(int j=0; j<num; j++){
			string s;
			cin >> s;
			words.insert(s);
			vs[i].insert(s);
		}
	}

	// todas as palavras 
	vector<string> vwords(words.begin(), words.end());

	for(int i=0; i<vwords.size(); i++){
		for(int j=i+1; j<vwords.size(); j++){
			bool oi=false, oj=false, bt=false;
			for(int k=0; k<vs.size(); k++){
				bool hasi=false, hasj=false;
				hasi = vs[k].count(vwords[i]);
				hasj = vs[k].count(vwords[j]);

				if(hasi && hasj) bt=true;
				else if(hasi && !hasj) oi=true;
				else if(!hasi && hasj) oj=true;
			}

			if(bt && oi && oj){
				cout << "no\n";
				return;
			}
		}
	}

	cout << "yes\n";
}

int main(){
	setIO("evolution");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
