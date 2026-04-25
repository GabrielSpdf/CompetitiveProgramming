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

void solve2stack(vector<vii> &v, int i, int j){
	int ans=0;
	vii path;

	while(v[i].size() || v[j].size()){
		path.push_back(make_pair(v[i].back().first+1, v[j].back().first+1));

		v[i].pop_back();
		v[j].pop_back();
		ans++;
	}

	cout << ans << "\n";
	for(int i=0; i<(int)path.size(); i++){
		cout << path[i].first << " " << path[i].second << "\n";
	}
}

void solve3stack(vector<vii> &v, int joker){
	int ans=0;
	vii path;

	while(v[1].size() || v[2].size() || v[0].size()){
		if(v[1].size()){
			path.push_back(make_pair(v[1].back().first+1, v[v[1].back().second].back().first+1));

			ii aux = v[1].back();

			v[1].back() = v[v[1].back().second].back();
			v[aux.second].pop_back();

			if(v[1].back().second == 1){
				joker = v[1].back().first;
				v[1].pop_back(); 
			}

			ans++;
		}
		else if(v[2].size() || v[0].size()){
			path.push_back(make_pair(joker+1, v[2].back().first));
			path.push_back(make_pair(v[2].back().first+1, v[0].back().first+1));
			path.push_back(make_pair(joker+1, v[0].back().first+1));

			v[2].pop_back();
			v[0].pop_back();

			ans+=3;
		}
	}

	cout << ans << "\n";
	for(int i=0; i<(int)path.size(); i++){
		cout << path[i].first << " " << path[i].second << "\n";
	}
}

void print_stack(vector<vii> &stacks){
	cout << "print...\n";
	for(int i=0; i<(int)stacks.size(); i++){
		cout << "i: " << i << "\n";
		for(int j=0; j<(int)stacks[i].size(); j++){
			cout << stacks[i][j].first << " " << stacks[i][j].second << "\n";
		}
	}
}

void solve(){
	int n;
	cin >> n;

	vi v(n), copy(n);
	int qtd0=0, qtd1=0, qtd2=0;
	int first=-1, second=-1, third=-1;
	for(auto &a: v){
		cin >> a;
		if(first==-1) first=a;
		else if(a != first && second==-1) second=a;
		else if(a != first && a != second && third==-1) third=a;

		if(a==0) qtd0++;
		if(a==1) qtd1++;
		if(a==2) qtd2++;
	}

	copy = v;
	sort(copy.begin(), copy.end());

	int div1=-1, div2=-1;

	for(int i=1; i<n; i++){
		if(copy[i]!=copy[i-1]){
			if(div1==-1) div1=i;
			else div2=i;
		}
	}
	

	vector<vii> stacks(3);

	int qtd=0;

	qtd += bool(qtd0) + bool(qtd1) + bool(qtd2);

	if(qtd==2){
		cout << "dois numeros\n";
		for(int i=0; i<n; i++){
			if(v[i] != copy[i]){
				int go;
				if(v[i]!=first) go=first;
				else go=second;

				stacks[v[i]].push_back(make_pair(i, go));
			}
		}
		
		/* print_stack(stacks); */
		solve2stack(stacks, first, second);
	}
	else if(qtd==3){
		/* cout << "tres numeros\n"; */

		/* cout << "div1: " << div1 << "\n"; */
		/* cout << "div2: " << div2 << "\n"; */
		int joker=-1;;
		for(int i=0; i<n; i++){
			if(v[i] != copy[i]){
				int go;

				if(i<div1) go=0;
				else if(i>=div1 && i<div2) go=1;
				else go=2;

				stacks[v[i]].push_back(make_pair(i, go));
			}
			else{
				if(v[i]==1) joker = i;
			}
		}
		
		/* print_stack(stacks); */
		solve3stack(stacks, joker);
	}
	else{
		cout << 0 << "\n";
	}

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
