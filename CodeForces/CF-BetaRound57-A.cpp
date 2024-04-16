//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2, s3;

    cin >> s1 >> s2;

    for(int i=0; i<(int)s1.size(); i++){
        if(s1[i] == s2[i]){ s3.append(to_string(0)); } else{ s3.append(to_string(1)); }
    }

    cout << s3 << endl;

    return 0;
}