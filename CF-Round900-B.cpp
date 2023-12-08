//Accepted

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long numT, n, p, i;
    vector<long long> meuV;
 
    cin >> numT;
 
    for(int q=0; q<numT; q++){
        cin >> n;
        p = 5;
        i = 5;
        meuV.push_back(2);
        meuV.push_back(3);
        meuV.push_back(4);
 
        while(meuV.size() < n){
            if((3*p) % (meuV[i-3] + meuV[i-4]) != 0) { meuV.push_back(p); }
 
            else { meuV.push_back(p+1); p++; }
            p++;
            i++;
        }
 
        for(int k=0; k<meuV.size(); k++){
            cout << meuV[k] << " ";
        }
        cout << endl;
 
        meuV.clear();
    }
 
 
    return 0;
}