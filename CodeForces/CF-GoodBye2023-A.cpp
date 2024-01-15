//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long lenb, n, inp, prod=1, qtd=0;
		vector<long long> v;

		cin >> lenb >> n;
		for(long long i=0; i<lenb; i++){
			cin >> inp;
			v.push_back(inp);
			prod*=inp;
		}

		if(prod==2023){
			cout << "YES" << endl;
			while(n--){
				cout << 1 << " ";
			}
			cout << endl; continue;
		}
		if(prod>2023){ cout << "NO" << endl; }
		if(prod<2023){
			if(prod==1){
				if(n>0){
					cout << "YES" << endl;
					cout << 2023 << " ";
					n--;
					while(n--){
						cout << 1 << " ";
					}
					cout << endl; continue;
				}
			}

			if(prod==119){
				if(n>0){
					cout << "YES" << endl;
					cout << 17 << " ";
					n--;
					while(n--){
						cout << 1 << " ";
					}
					cout << endl; continue;
				}
			}

			if(prod==289){
				if(n>0){
					cout << "YES" << endl;
					cout << 7 << " ";
					n--;
					while(n--){
						cout << 1 << " ";
					}
					cout << endl; continue;
				}
			}

			if(prod==17){
				if(n>0){
					cout << "YES" << endl;
					cout << 119 << " ";
					n--;
					while(n--){
						cout << 1 << " ";
					}
					cout << endl; continue;
				}
			}
			if(prod==7){
				if(n>0){
					cout << "YES" << endl;
					cout << 289 << " ";
					n--;
					while(n--){
						cout << 1 << " ";
					}
					cout << endl; continue;
				}
			}

			cout << "NO" << endl;
			

		}
	}




	return 0;
}
