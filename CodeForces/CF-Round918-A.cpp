//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c, diff;
		cin >> a >> b >> c;
		if(a-b==0){diff=c;}
		if(b-c==0){diff=a;}
		if(a-c==0){diff=b;}


		cout << diff << endl;
	}



	return 0;
}
