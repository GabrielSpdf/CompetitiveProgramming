//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, contador=0;
    string s;

    cin >> n >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == s[i+1]){ contador++; }
    }

    cout << contador << endl;

    return 0;
}