//Accepted

#include <bits/stdc++.h>

using namespace std;


int main(){
	int cases;

	cin >> cases;

	for(int i=0; i<cases; i++){
		int a, end, valor, maior_dif=0, maior, menor;

		cin >> a >> end;

		vector<int> vetor;

		vetor.push_back(0);
		for(int j=0; j<a; j++){
			cin >> valor;
			vetor.push_back(valor);
		}	
		vetor.push_back(end);



		/* cout << "vetor size: " << vetor.size() << endl; */

		for(int k=1; k<vetor.size(); k++){
			/* cout << "vetor size: " << vetor.size(); */
			if((vetor[k]-vetor[k-1]) >= maior_dif) { maior_dif = vetor[k]-vetor[k-1]; maior = vetor[k]; menor = vetor[k-1]; } 
			/* cout << "maior dif atual: " << maior_dif << endl; */
		}

		if(2*(vetor[vetor.size()-1] - vetor[vetor.size()-2]) > maior_dif) { maior_dif = 2*(vetor[vetor.size()-1] - vetor[vetor.size()-2]); }

		/* cout << "maior: " << maior << " menor: " << menor << endl; */

		if(vetor.size() == 2) { maior_dif = vetor[1] - vetor[0]; maior = vetor[1]; menor = vetor[0]; }

		if(maior == end && menor == 0) { cout << 2*maior_dif << endl; }
		else{ cout << maior_dif << endl; }

		vetor.clear();
	}



	return 0;
}	
