//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int lw=0, up=0;

    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == tolower(s[i])){ lw++; } else{ up++; }
    } 

    if(lw >= up){ transform(s.begin(), s.end(), s.begin(), ::tolower); }

    else{ transform(s.begin(), s.end(), s.begin(), ::toupper); }

    cout << s << endl;

    return 0;
}