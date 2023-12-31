//Accepted

#include <bits/stdc++.h>

using namespace std;

#define ll long long;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, p, i=0;
	while(cin >> n >> p){
		++i;
		if(n==0 && p==0){ break; }
		if(i>1){ cout<<endl; }

		vector<string> v;
		cin.ignore();
		for(int i=0; i<n; i++){
			string s;
			/* cin.ignore(); */
			getline(cin, s, '\n');
		}

		int maior=-1, var=0;
		double min;
		string ans;
		for(int j=0; j<p; j++){
			string t;
			double d;
			int r;
			/* char nextChar = cin.peek(); */
			/* if(isspace(nextChar)){ cin.ignore(); } */
			getline(cin, t, '\n');
			cin >> d >> r;
			cin.ignore();

			if(r>maior){
				var=0;
				v.clear();
				maior=r;
				v.push_back(t);
				min=d;
			}

			else if(r==maior){
				v.push_back(t);
				if(d<min){ var=1; ans=t; min=d; }
			}

			for(int k=0; k<r; k++){
				string u;
				/* cin.ignore(); */
				getline(cin, u, '\n');
			}
		}
		cout << "RFP #" << i << endl;;
		if(v.size()==1){ cout << v.back() << endl; }
		if(v.size()>1){ if(var==0){ cout << v[0] << endl; } if(var==1){ cout << ans << endl; } }
	}
	
	return 0;
}
