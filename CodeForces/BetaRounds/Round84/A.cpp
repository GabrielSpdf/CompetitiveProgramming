//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int ln=0;

    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == '7' || s[i] == '4'){ ln++; }
    }

    if(ln == 7 || ln == 4){ cout << "YES" << endl; } else{ cout << "NO" << endl; }


    return 0;
}