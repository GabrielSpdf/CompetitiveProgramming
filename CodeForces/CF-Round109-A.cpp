//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, maior, menor, cont=0;
    cin >> n;
    cin >> a;
    maior = a; menor = a;

    for(int i=1; i<n; i++){
        cin >> a;
        if(a>maior){ cont++; maior = a; }
        if(a<menor){ cont++; menor = a; }
    }

    cout << cont << endl;

    return 0;
}