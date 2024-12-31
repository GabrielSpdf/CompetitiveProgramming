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
	int inp;
	map<int, int> m;
	for(int i=0; i<4; i++){
		cin >> inp;
		m[inp]++;
	}
	
	bool ans1=false, ans2=false;
	for(auto el : m){
		if(ans1==false && el.second==2) ans1=true;	
		else if(ans2==false && el.second==2) ans2=true;
	}

	bool ans3=false, ans4=false;
	for(auto el : m){
		if(ans3==false && el.second==1) ans3=true;	
		if(ans4==false && el.second==3) ans4=true;
	}

	if((ans1==true && ans2==true) || (ans3==true && ans4==true)) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
