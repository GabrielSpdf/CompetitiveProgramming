#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
void hanoi(int n, int origem, int destino, int auxiliar, vii &moves){
    // Caso base: apenas um disco para mover
	if(n==1){
		moves.push_back(make_pair(origem, destino));
		return;
	}
 
    // Mover n-1 discos de origem para auxiliar, usando destino como auxiliar
	hanoi(n-1, origem, auxiliar, destino, moves);
 
    // Mover o disco n de origem para destino
	moves.push_back(make_pair(origem, destino));
 
    // Mover n-1 discos de auxiliar para destino, usando origem como auxiliar
	hanoi(n-1, auxiliar, destino, origem, moves);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
	int n;
 
	cin >> n;
 
	vii moves;
 
	hanoi(n, 1, 3, 2, moves);
 
	cout << moves.size() << "\n";
	for(auto &a:moves) cout << a.first << " " << a.second << "\n";
 
    return 0;
} 
