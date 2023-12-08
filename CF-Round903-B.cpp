//Accepted

#include <bits/stdc++.h>

using namespace std;


void confere(vector<int> n){
    int maior, menor, verifica;
    vector<int> copia_n;

    for(int i=0; i<4; i++){
        verifica = 0;
        copia_n = n;
        sort(n.begin(), n.end()); //ordem crescente
        maior = n.back(); menor = n.front();
        //cout << "maior: " << maior << " menor: " << menor << endl; 
        n.pop_back();
        n.push_back(maior-menor); n.push_back(menor);

        while(!copia_n.empty()){
            if(copia_n.back() != copia_n.front()){ verifica=1; break; }
            copia_n.pop_back();
        }

        if(verifica == 0){ cout << "YES" << endl; return; }
    }

    if(verifica == 1) { cout << "NO" << endl; }
}

int main(){
    int cases;

    cin >> cases;

    for(int i=0; i<cases; i++){
        vector<int> n;
        int p1, p2, p3;

        cin >> p1 >> p2 >> p3;
        n.push_back(p1); n.push_back(p2); n.push_back(p3);


        if(p1 == p2 && p2 == p3 && p1 == p3) {cout << "YES" << endl;}

        else{ confere(n); }
    }

    return 0;
}