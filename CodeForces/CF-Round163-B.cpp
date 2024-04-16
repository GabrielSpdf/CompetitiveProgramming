//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    string s;

    cin >> a >> b;
    cin >> s;

    for(int j=0; j<b; j++){
        for(int i=0; i<(int)s.size()-1; i++){
            if(s[i] == 'B' && s[i+1] == 'G'){ swap(s[i], s[i+1]); i++; }
        }
    }

    cout << s << endl;

    return 0;
}