//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int test;

	cin >> test;

	for(int i=0; i<test; i++){
		vector<int> verifica;
		vector<string> alf = {"a","b","c","d","e","f","g","h"};
		verifica.push_back(1);
		verifica.push_back(2);
		verifica.push_back(3);
		verifica.push_back(4);
		verifica.push_back(5);
		verifica.push_back(6);
		verifica.push_back(7);
		verifica.push_back(8);
		string pos1;

		cin >> pos1;
		int pos2 = pos1[1]-48;

		verifica[pos2-1] = -1;

		while(!verifica.empty()){
			if (verifica.back() != -1) {cout << pos1[0] << verifica.back() << endl;}
			verifica.pop_back();
		}

		while(!alf.empty()){
			if(alf.back()[0] != pos1[0]) {cout << alf.back() << pos2 << endl;}
			alf.pop_back();
		}
	}

	return 0;
}
