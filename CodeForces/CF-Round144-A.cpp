//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, arr[101], j=1, cont=0;
    vector<int> outp;

    cin >> n;

    for(int i=1; i<n+1; i++){
        arr[i] = i; 
    }

    for(int i=1; i<n+1; i++){
        if(arr[i] != j && arr[i]!= -1){ outp.push_back(arr[i]); arr[i]= -1; j++; i=0; cont++; } 
    }

    if(cont!=n){ cout << -1 << endl; }
    else{
        for(int k=0; k<(int)outp.size(); k++){
            cout << outp[k] << " ";
        }
    }

    return 0;
}