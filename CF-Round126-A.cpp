//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    float sum=0, inp;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> inp;
        sum+=inp/100.0;
    }

    cout << (sum/n)*100 << endl;

    return 0;
}