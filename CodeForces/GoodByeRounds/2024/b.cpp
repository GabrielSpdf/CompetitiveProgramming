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
        int n; cin >> n;

        vector<int> L(n), R(n);
        for(int i = 0; i < n; i++){
            cin >> L[i] >> R[i];
        }

        int maxVal = 2*n;
        vi forcedCount(maxVal+1, 0);

        for(int i = 0; i < n; i++){
            if(L[i] == R[i]){
                forcedCount[L[i]]++;
            }
        }

        vi F(maxVal+1, 0);
        for(int x = 1; x <= maxVal; x++){
            if(forcedCount[x] >= 1) F[x] = 1;
        }
        vi P(maxVal+1, 0);
        for(int x = 1; x <= maxVal; x++){
            P[x] = P[x-1] + F[x];
        }

        string ans(n, '0');
        for(int i = 0; i < n; i++){
            int l = L[i], r = R[i];
            if(l == r){
                int x = l;
                if(forcedCount[x] == 1) ans[i] = '1';
                else ans[i] = '0';
            } else {
                int total = (r - l + 1);
                int ocupados = P[r] - P[l-1];
                int livres = total - ocupados;
                if(livres > 0) ans[i] = '1';
                else ans[i] = '0';
            }
        }

        cout << ans << "\n";
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
