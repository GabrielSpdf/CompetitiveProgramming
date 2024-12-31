//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector<vector<ll>> matrix(n, vector<ll>(m));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> matrix[i][j];	
			}
		}

		/* for(int i=0; i<n; i++){ */
		/* 	for(int j=0; j<m; j++){ */
		/* 		cout << matrix[i][j] << " "; */
		/* 	} */
		/* 	cout << "\n"; */
		/* } */

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(n==1 && m>1){
					if(j>0 && j<(m-1)){
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i][j-1], matrix[i][j+1]))){
							matrix[i][j] = max(matrix[i][j+1], matrix[i][j-1]);
						}
					}

					if(j==0){
						if(matrix[i][j] == max(matrix[i][j], matrix[i][j+1])){
							matrix[i][j] = matrix[i][j+1];
						}
					}	

					if(j==(m-1)){
						if(matrix[i][j] == max(matrix[i][j], matrix[i][j-1])){
							matrix[i][j] = matrix[i][j-1];
						}
					}
				}

				else if(n>1 && m==1){
					if(i>0 && i<(n-1)){
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i-1][j], matrix[i+1][j]))){
							matrix[i][j] = max(matrix[i-1][j], matrix[i+1][j]);
						}
					}

					if(i==0){
						if(matrix[i][j] == max(matrix[i][j], matrix[i+1][j])){
							matrix[i][j] = matrix[i+1][j];
						}
					}	

					if(i==(n-1)){
						if(matrix[i][j] == max(matrix[i][j], matrix[i-1][j])){
							matrix[i][j] = matrix[i-1][j];
						}
					}

				}

				else if(n>1 && m>1){
					if(i == 0 && j == 0){ //apenas direita e baixo
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i+1][j], matrix[i][j+1]))){
							matrix[i][j] = max(matrix[i][j+1], matrix[i+1][j]);
						}

					}

					else if(i == 0 && j == (m-1)){ //apenas esquerda e baixo
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i+1][j], matrix[i][j-1]))){
							matrix[i][j] = max(matrix[i][j-1], matrix[i+1][j]);
						}
					}

					else if(i == (n-1) && j == 0){ //apenas direita e cima
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i-1][j], matrix[i][j+1]))){
							matrix[i][j] = max(matrix[i][j+1], matrix[i-1][j]);
						}
					}

					else if(i == (n-1) && j == (m-1)){ //apenas esquerda e cima
						if(matrix[i][j] == max(matrix[i][j], max(matrix[i-1][j], matrix[i][j-1]))){
							matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
						}
					}

					else if(i == 0 && (j>0 && j<(m-1))){ //nao olha para cima
						if(matrix[i][j] == max(max(matrix[i][j], matrix[i][j+1]), max(matrix[i+1][j], matrix[i][j-1]))){
							matrix[i][j] = max(matrix[i][j+1], max(matrix[i+1][j], matrix[i][j-1]));
						}
					}

					else if(i == (n-1) && (j>0 && j<(m-1))){ //nao olha para baixo
						if(matrix[i][j] == max(max(matrix[i][j], matrix[i][j+1]), max(matrix[i-1][j], matrix[i][j-1]))){
							matrix[i][j] = max(matrix[i][j+1], max(matrix[i-1][j], matrix[i][j-1]));
						}
					
					}

					else if(j == 0 && (i>0 && i<(n-1))){ //nao olha para esquerda
						if(matrix[i][j] == max(max(matrix[i][j], matrix[i][j+1]), max(matrix[i-1][j], matrix[i+1][j]))){
							matrix[i][j] = max(matrix[i][j+1], max(matrix[i-1][j], matrix[i+1][j]));
						}

					}

					else if(j == (m-1) && (i>0 && i<(n-1))){ //nao olha para direita
						if(matrix[i][j] == max(max(matrix[i][j], matrix[i][j-1]), max(matrix[i-1][j], matrix[i+1][j]))){
							matrix[i][j] = max(matrix[i][j-1], max(matrix[i-1][j], matrix[i+1][j]));
						}
					}
					
					else if(matrix[i][j] == max(max(max(matrix[i][j+1], matrix[i][j]), matrix[i][j-1]), max(matrix[i-1][j], matrix[i+1][j]))){
						matrix[i][j] = max(max(matrix[i][j+1], matrix[i][j-1]), max(matrix[i-1][j], matrix[i+1][j]));
					}
				}

			}
		}	
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}

    return 0;
}
