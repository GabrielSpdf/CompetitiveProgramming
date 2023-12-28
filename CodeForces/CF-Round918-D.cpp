//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
	int time;
	cin>>time;
	while(time--){
		int len,qtd=0, saiu=0;
		string s, t;
		cin>>len>>s;

		/* cout << "s[0]: " << s[0] << endl; */
		/* t+=s[0]; */
		/* cout << "t_append s[0]: " << t << endl; */

		for(int i=0; i<s.size(); i++){
			if(qtd<2 || i==s.size()-1){
				t+=s[i]; qtd++; continue;
			}

			
			if(s[i]=='b' || s[i]=='c' || s[i]=='d'){
				if(s[i+1]=='b' || s[i+1]=='c' || s[i+1]=='d'){
					t+=s[i]; t+='.'; continue; 
				}
				else{
					if(t.back()!='.')t+='.'; 

					t+=s[i]; continue;
				}
			}
			else{
				t+=s[i]; continue;
			}
		}

		/* cout << t << endl; */
		cout << t << endl;
		t.clear();
	}

	return 0;
}
