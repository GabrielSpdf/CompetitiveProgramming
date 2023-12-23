//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;

	for(long long i=0; i<n; i++){
		long long a,b;
		cin >> a >> b;
		vector<long long> first(a);
		vector<long long> second(a);

		long long lim=a;

		vector<long long> sum1(a, 0);

		for(long long j=0; j<lim; j++){
			cin >> first[j];
			if(j==0){sum1[0]=first[j];}
			if(j>0){sum1[j]=sum1[j-1]+first[j];}
		}

		for(long long l=0; l<lim; l++){
			cin >> second[l];
		}

		long long sum=0, mvs=second[0];
		// 2  3
		// 1  1
		// 2  3

		//if(a==1 || b==1){ cout<< first[0]+(b-1)*second[0] << endl; continue; }

		for(long long k=0; k<min(a,b); k++){
			mvs = max(mvs, second[k]);
			sum = max(sum1[k]+((b-k-1)*mvs), sum);
			//if(sum1[k-1]+((b-k)*second[k-1]) > sum) { mvs = second[k-1];  sum = sum1[k-1]+((b-k)*second[k-1]); }
			//if(sum1[k]+((b-k-1)*second[k]) > sum) { if((b-k-1)>0){mvs = second[k];} sum = sum1[k]+((b-k-1)*second[k]); }
		}

		//expected: '39', found: '38'
		cout << sum << endl;

	}

	return 0;
}
