//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int j=0; j<t; j++){
		int n, inp, maior=0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> inp;
			if(inp>=maior){maior=inp;}
		}
		cout << "Case " << j+1 << ": " << maior << endl; 
	}

	return 0;
}
