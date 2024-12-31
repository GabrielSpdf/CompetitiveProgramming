#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void analyze(string& s, int ans, int index){
	string out;
	int look, size=(int)s.size();

	if(size-index>4) look=4;
	else look=(size-index);

	if(ans>0) out="YES";
	else out="NO";

	if(s[index])

}

void solve(){
	string s;
	int q, inp1, inp2, ans=0;
	vii v;

	cin >> s;
	cin >> q;

	for(int i=0; i<q; i++){
		cin >> inp1 >> inp2;
		v.emplace_back(make_pair(inp1, inp2));
	}

	vi aux(s.size());
	
	if(s[0]=='0') aux[0]=0;
	else aux[0]=1;

	for(int i=1; i<(int)s.size(); i++){
		if(s[i]=='1' && aux[i-1]==0) aux[i]=1;
		if(s[i]=='0' && aux[i-1]==0) aux[i]=0;

		if(s[i]=='1' && aux[i-1]==1) aux[i]=2;
		if(s[i]=='0' && aux[i-1]==1) aux[i]=0;

		if(s[i]=='0' && aux[i-1]==2) aux[i]=3;
		if(s[i]=='1' && aux[i-1]==2) aux[i]=2;

		if(s[i]=='0' && aux[i-1]==3){ aux[i]=4; ans++; }
		if(s[i]=='1' && aux[i-1]==3) aux[i]=1;

		if(s[i]=='0' && aux[i-1]==4) aux[i]=0;
		if(s[i]=='1' && aux[i-1]==4) aux[i]=1;
	}

	for(int i=0; i<q; i++){
		s[v[i].first] = v[i].second;
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
