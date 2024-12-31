#include <bits/stdc++.h>

using namespace std;

const int64_t MAX = INT64_MAX;
const int64_t MIN = INT64_MIN;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
    string s;
    int pamonha = 0, q;
    cin >> s;

    for (int i=0; i<(int)s.size()-3; i++) if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') pamonha++;

    cin >> q;

    while (q--){
		int i, v;
        cin >> i >> v;
        i--;

        if(s[i]-'0'==v){
			if(pamonha>0) cout << "YES\n";
			else cout << "NO\n";
            continue;
        }

        if (i>1 && i<(int)s.size()-1){
            if (s[i-2] == '1' && s[i-1] == '1' && s[i+1] == '0') {
                if (s[i] == '0') {
                    pamonha--;
                } else {
                    pamonha++;
                }
            }
        }

        if(i > 2){
            if(s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0'){
                if (s[i] == '0') pamonha--;
                else pamonha++;
            }
        }

        if(i<(int)s.size()-3){
            if(s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
                if (s[i] == '0') pamonha++;
                else pamonha--;
            }
        }

        if(i>0 && i<(int)s.size()-2){
            if(s[i-1] == '1' && s[i+1] == '0' && s[i+2] == '0'){
                if (s[i] == '0') pamonha++;
                else pamonha--;
            }
        }
        if (s[i] == '0') s[i]='1';
        else s[i]='0';
		
		if(pamonha>0) cout << "YES\n";
		else cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}
