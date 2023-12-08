//Accepted

#include <bits/stdc++.h>

using namespace std;


int main(){
	int n, test;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> test;
		if((test + 1) % 3 == 0 || (test - 1) % 3 == 0) { cout << "First" << endl; } 
		else { cout << "Second" << endl; }
	}

	return 0;
}
