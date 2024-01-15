#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int inpx, inpy, x1=0, x2=0, y1=0, y2=0, lin, col;
		for(int i=0; i<4; i++){
			cin >> inpx >> inpy;
			if(x1==0){ x1 = inpx; }
			else{ if(inpx!=x1) x2 = inpx; }
			if(y1==0){ y1 = inpy; }
			else{ if(inpy!=y1) y2 = inpy; }
		}


		if(x1<0){ x2-=x1; x1-=x1; }
		if(x2<0){ x1-=x2; x2-=x2; }
		if(y1<0){ y2-=y1; y1-=y1; }
		if(y2<0){ y1-=y2; y2-=y2; }

		cout << abs(x1-x2)*abs(y1-y2) << endl;
	}


	return 0;
}


