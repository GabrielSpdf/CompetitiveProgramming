//Accepted

#include <bits/stdc++.h>

using namespace std;


int main(){
	long long n, b, nh, nw;

	while(cin >> n >> b >> nh >> nw){
		long long arr[20][15];
	    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqueue;					

		for(long long i=0; i<nh; i++){
			cin >> arr[i][0]; //pp
			pqueue.emplace(arr[i][0], i);

			for(long long j=1; j<=nw; j++){
				cin >> arr[i][j];
			}
		}

		long long cm=0, max=n, var=0;
		while(!pqueue.empty() && var==0){
			pair<int,int> p = pqueue.top();
			/* cout << "menor valor hotel: " << p.first << endl; */
			/* cout << "index: " << p.second << endl; */
			if(p.first*n <= b){
				for(int k=1; k<=nw; k++){
					/* cout<<arr[p.first][k]<<" "; */
					if(arr[p.second][k]>=max){ cm+=p.first*max; var=1; break; }
				}
			}

			pqueue.pop();
		}

		if(cm==0){cout << "stay home" << endl;}
		else{cout << cm << endl;}
	}

	return 0;
}
