//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	for(int p=0; p<cases; p++){
		string s;
		cin >> s;

		int initu=0, initz=0, ver=0;
	
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]=='0'){initz++;}
			if(s[i]=='1'){initu++;}
		}

		int qtdu, qtdz, cont=0;
		qtdu = initu; qtdz = initz;
		//cout << "qtdu: " << qtdu << endl;
		//cout << "qtdz: " << qtdz << endl;

		if(qtdu==qtdz){ cout << 0 << endl; continue; }
		if(s.size()==1){cout << 1 << endl; continue; }
		for(int j=(int)s.size()-1; j>=0; j--){
			if(s[j]=='0'){qtdz--; cont++; }
			if(s[j]=='1'){qtdu--; cont++; }
			if(qtdu==qtdz){ cout << cont << endl; break; }

			if(initz-qtdz>0 && qtdu>qtdz){
				for(int k=1; k<=(initz-qtdz); k++){
					if(qtdu-k==qtdz){ cout << cont << endl; ver=1; break; }
				}
			}
			if(initu-qtdu>0 && qtdz>qtdu){
				for(int l=1; l<=(initu-qtdu); l++){
					if(qtdz-l==qtdu){ cout << cont << endl; ver=1; break; }
				}
			}
			if(ver==1){ break; }

			//if(qtdu-1==qtdz && (initz-qtdz)>0){ cout << cont << endl; break; }
			//if(qtdz-1==qtdu && (initu-qtdu)>0){ cout << cont << endl; break; }

			if(qtdz==0){ cout << initu << endl; break; }
			if(qtdu==0){ cout << initz << endl; break; }
		}
	}

	return 0;
}
