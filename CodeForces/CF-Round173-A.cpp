//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, var=0, ver=0;
    string s;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<(int)s.size(); j++){
            if(s[j] == '-'){ ver=-1; }
            if(s[j] == '+'){ ver=1; }
        }

        if(ver==1){ var++; }
        if(ver==-1){ var--;}
    }

    cout << var << endl;

    return 0;
}