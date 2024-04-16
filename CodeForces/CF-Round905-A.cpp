//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, contador = 4;

    cin >> cases;
    for(int i=0; i<cases; i++){
        string inp;
        cin >> inp;

        for(int j=0; j<(int)inp.size()-1; j++){
            int aux1 = inp[j] - '0', aux2 = inp[j+1] - '0';
            if(aux1 == 0){ aux1 = 10; } if(aux2 == 0){ aux2 = 10; }

            if(j==0) { contador += (aux1-1)+abs(aux1-aux2); }
            if(j!=0) { contador += abs(aux1-aux2); }
            
        }
        cout << contador << endl;
        contador = 4;
    }

    return 0;
}