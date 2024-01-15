//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    //int a = 'A' - 64; == 1
    //cout << a << endl;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        vector<int> alf(26, 0), ver(26,0);
        int a, cont=0;
        string s;

        cin >> a >> s;

        for(int j=0; j<(int)s.size(); j++){
            alf[s[j] - 65]++;
        }

        for(int l=0; l<26; l++){
            ver[l]=l+1;
        }

        for(int k=0; k<26; k++){
            if(alf[k] >= ver[k]){ cont++; }
        }

        cout << cont << endl;
    }



    return 0;
}