//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, len;
    string s;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        len = s.size();
        if(len>10){ cout << s[0] << len-2 << s[s.size()-1] << endl; }else{ cout << s << endl; }
    }

    return 0;
}