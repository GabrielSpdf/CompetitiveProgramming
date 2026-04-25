//Accepted

#include <bits/stdc++.h> 

using namespace std;

int main(){
	int cases;

	cin >> cases;
 
	for(int i=0; i<cases; i++){
		string frase;
		cin >> frase;
		vector<int> lowercase;
		vector<int> uppercase;

		for(int j=0; j<frase.size(); j++){
			if(frase[j]==toupper(frase[j]) && frase[j]!='B'){  uppercase.push_back(j); }

			else if(frase[j]==toupper(frase[j]) && frase[j]=='B' && uppercase.size()>0){ uppercase.pop_back(); }

			else if(frase[j]==tolower(frase[j]) && frase[j]!='b'){ lowercase.push_back(j); }

			else if(frase[j]==tolower(frase[j]) && frase[j]=='b' && lowercase.size()>0){ lowercase.pop_back(); }
		}

		int lo=0, up=0;
		for(int k=0; k<frase.size(); k++){
			if(lowercase.size()!=lo && lowercase.size()>0){
				if(lowercase[lo] == k){
					cout << frase[k];
					lo++;
				}
			}

			if(uppercase.size()!=up && uppercase.size()>0){
				if(uppercase[up] == k){
					cout << frase[k];
					up++;
				}
			}
		}
		cout << endl;

	}

	return 0;
}
