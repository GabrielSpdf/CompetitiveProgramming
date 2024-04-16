//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	while(cin >> t){
		int inp, aux=0;
		vector<int> v, ver(3001, 0);
		for(int k=0; k<t; k++){
			cin >> inp;
			v.push_back(inp);
		}

		for(int i=0; i<v.size()-1; i++){
			ver[abs(v[i]-v[i+1])]=1;
		}

		for(int j=1; j<t; j++){
			if(ver[j]!=1 && aux==0){cout<<"Not jolly"<<endl; aux=1;}
		}

		if(aux==0){cout << "Jolly" << endl;}
	}

	return 0;
}
