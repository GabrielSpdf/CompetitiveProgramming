//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, k, myrt, inp;
		cin >> n >> k;

		vector<ll> v1, v2;

		//Preenche vetor e procura my rating
		for(ll i=0; i<n; i++){
			cin >> inp;
			v1.push_back(inp);

			if(i==(k-1)) myrt = inp;
		}

		v2 = v1;
		ll ind=0;

		//Encontra o primeiro elemento maior que o my rating
		for(ll j=0; j<n; j++){
			if(v1[j]>=myrt && j<(k-1)){ ind=j; break; }
		}

		//Swap nos vetores
		swap(v1[k-1], v1[0]); //comeca do indice 0
		swap(v2[ind], v2[k-1]); //swapa com o primeiro elemento maior que o my rating

		ll seq1=0, seq2=0, ver=0, maior=-1;

		//Processo no v1
		for(ll l=0; l<n; l++){
			if(v1[l]>maior) maior=v1[l];

			if(myrt<maior){	
				if(l<0) seq1=0;
				break;  
			}

			if(v1[l]==myrt){
				if(l>0 && v1[l]>v1[l-1]) seq1++;
			}

			if(l>0) seq1++;
		}

		maior=-1;

		//Processo no v2
		for(ll m=0; m<n; m++){
			if(v2[m]>maior) maior=v2[m];

			if(myrt<maior){ 
				if(m<ind) seq2=0;
				break;  
			}

			if(v2[m]==myrt){
				if(m>0 && v2[m]>v2[m-1]) { seq2++; }
			}

			if(m>ind) { seq2++; }

		}

		cout << max(seq1, seq2) << "\n";
	}


    return 0;
}
