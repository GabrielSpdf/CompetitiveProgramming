//Accepted

#include <bits/stdc++.h>

using namespace std;

string op(vector<int> v){
	for(int i=1; i<(int)v.size()-1; i++){
		int op1, op2, op3, op;
		op1=v[i]/2;
		op2=v[i-1];
		op3=v[i+1];
		
		op = min(min(op1, op2), op3);
		v[i]-=2*op; v[i-1]-=op; v[i+1]-=op;
	}

	int ver=0;
	for(int i=0; i<(int)v.size(); i++){
		if(v[i]!=0){ ver=1; }
	}
	
	return ver==1? "NO\n": "YES\n"; 
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		
		cout << op(v);
	}

	return 0;
}
