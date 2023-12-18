//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, cont=0, maior=0;

    cin >> n >> a >> b;
    cont+=b-a;
    if(cont>maior){ maior = cont; }
    for(int i=1; i<n; i++){
        cin >> a >> b;
        cont+=b-a;
        if(cont>maior){ maior = cont; }
    }

    cout << maior << endl;

    return 0;
}