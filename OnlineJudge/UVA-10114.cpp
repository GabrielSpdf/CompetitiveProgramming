//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	while(1){
		int d, n, inp1, ans=0, sub;
		double p, l, inp2;

		cin >> d >> p >> l >> n;

		if(d<0){ return 0; }
		vector<pair<int,double>> v;

		for(int i=0; i<n; i++){
			cin >> inp1 >> inp2;
			v.emplace_back(inp1, inp2);
		}

		sub=l/d;
		double car_v=l, car=p+l;
		car*=(1-v[0].second);

		int k=0;
		while(car_v>=car){
			ans++;
			car_v-=sub;
			/* if(car>car_v){break;} */

			if(k<(n-1) && ans==(v[k+1].first)){k++;}
			car*=(1-v[k].second);
			/* if(car_v>=car){ans++;} */
		}

		if(ans==1){cout<<ans<<" month"<<endl;} else{cout<<ans<<" months"<<endl;}
	}
	return 0;
}
