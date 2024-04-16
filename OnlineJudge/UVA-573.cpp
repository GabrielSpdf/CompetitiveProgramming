//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	double h,u,d,f;
	while(1){
		cin >> h >> u >> d >> f;
		if(h < 1 || u < 1 || d < 1 || f < 1){break;}

		double alt=0, up=u, i=0, sub;
		sub=u*(f*0.01);
		while(1){
			i++;
			alt+=up;
			if(alt>h){ cout << "success on day " << i << endl; break;}
			alt-=d;
			if(alt<0){ cout << "failure on day " << i << endl; break;}
			if(up-sub>=0){up-=sub;}
		}
	}

	return 0;
}
