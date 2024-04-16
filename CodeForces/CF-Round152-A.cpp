//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ce=0, oe=0, cd=0, od=0, a, b, cont=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a==0){ce++;}else{oe++;}
        if(b==0){cd++;}else{od++;}
    }

    if(ce>oe){ cont+= oe; }else{ cont+= ce; }

    if(cd>od){ cont+= od; }else{ cont+= cd; }

    cout << cont << endl;

    return 0;
}