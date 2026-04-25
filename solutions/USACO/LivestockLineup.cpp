#include <bits/stdc++.h>
#include <sstream>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

map<string, vector<string>> ms;
map<string, bool> visited;
string comp;

void idhead(string name){
	if(visited[name]==true) return;

	visited[name]=true;
	if(ms[name].size()==1){
		comp = min(comp, name);
	}

	for(auto nxt : ms[name]) idhead(nxt);		
}

void printdfs(string name){	
	if(visited[name]==true) return;

	visited[name]=true;
	cout << name << "\n";
	for(auto nxt : ms[name]) printdfs(nxt);
}

void solve(){
	int n;
	cin >> n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- important

	ms.clear();
	visited.clear();
	
	for(int i=0; i<n; i++){
		string s;
		getline(cin, s);

		istringstream iss(s);
		string word;
		vector<string> words;
		while(iss >> word){
			words.push_back(word);
		}
		ms[words[0]].push_back(words[words.size()-1]);
		ms[words[words.size()-1]].push_back(words[0]);
	}
	
	vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	vector<string> order;
	for(int i=0; i<(int)names.size(); i++){
		comp="ZZZ";

		if(visited[names[i]]==false){
			if(ms[names[i]].size()==1){
				/* cout << "names[i]: " << names[i] << "\n\n\n"; */
				idhead(names[i]);			
				order.push_back(comp);
			}
			else if(ms[names[i]].size()==0){
				order.push_back(names[i]);
			}
		}
	}

	/* cout << "pre: "; */
	/* for(int i=0; i<(int)order.size(); i++) cout << order[i] << " "; */
	/* cout << "\n"; */
	sort(order.begin(), order.end());
	/* cout << "pos: "; */
	/* for(int i=0; i<(int)order.size(); i++) cout << order[i] << " "; */
	/* cout << "\n"; */
	visited.clear();
	for(int i=0; i<(int)order.size(); i++){
		if(ms[order[i]].size()==1) printdfs(order[i]);
		else cout << order[i] << "\n";
	}
}

int main(){
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
