#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	int t_sum = n*(n+1)/2;

	if(t_sum%2){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";

	vector<int> st1, st2;

	if(n%4==0){
		for(int i=0; i<n/4; i++){
			st1.push_back(i+1);
			st1.push_back(n-i);
		}
		for(int i=n/4; i<n/2; i++){
			st2.push_back(i+1);
			st2.push_back(n-i);
		}
	}
	else{
		st1.push_back(1);
		st1.push_back(2);
		st2.push_back(3);

		int m = (n-3)/4;
		for(int i=0; i<m; i++){
			st1.push_back(4+i);
			st1.push_back(n-i);
		}
		for(int i=0; i<m; i++){
			st2.push_back(4+m+i);
			st2.push_back(n-m-i);
		}
	}

	cout << st1.size() << "\n";
	for(auto &a: st1){
		cout << a << " ";
	}
	cout << "\n";
	cout << st2.size() << "\n";
	for(auto &a: st2){
		cout << a << " ";
	}
	cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
