//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int cont=0;
    string s;
    vector<int> ver(100,-1);

    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        ver[s[i]-'0'] = s[i]-'0';
    }

    for(int j=0; j<(int)ver.size(); j++){
        if(ver[j] != -1){ cont++; }
    }

    if(cont%2 != 0){ cout << "IGNORE HIM!" << endl; } else{ cout << "CHAT WITH HER!" << endl; }

    return 0;
}