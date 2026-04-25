//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//Vanya - start at 1th
//Petya - start at nth
//Sasha - same number of comp between Vanya and Petya
int main(){
	ll n, m, pt=0, pv=0;
	cin >> n;

	vector<ll> arr(n), q(100001, -1), ind(100001, -1);
	for(ll i=0; i<n; i++){
		cin >> arr[i];
		ind[arr[i]]=i;
	}

	cin>>m;

	vector<ll> query(m);
	for(ll j=0; j<m; j++){
		cin >> query[j];
		if(q[query[j]]>=1){ q[query[j]]++; }
		if(q[query[j]]==-1){ q[query[j]]=1; }
	}


	for(ll l=0; l<arr.size(); l++){
		if(q[arr[l]]!=-1){ pt+=(arr.size()-ind[arr[l]])*q[arr[l]]; pv+=(ind[arr[l]]+1)*q[arr[l]]; }
	}

	//pt+=arr.size()-k*q[arr[k]]
	//pv+=(k+1)*q[arr[k]]


	cout << pv << " " << pt << endl;

	return 0;
}
