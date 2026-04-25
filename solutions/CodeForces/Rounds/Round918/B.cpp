//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a=0,b=0,c=0;
		char s;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cin >> s;
				if(s=='A'){a++;}
				if(s=='B'){b++;}
				if(s=='C'){c++;}
			}
		}

		if(a<3){cout<<"A"<<endl;}
		if(b<3){cout<<"B"<<endl;}
		if(c<3){cout<<"C"<<endl;}
	}




	return 0;
}
