//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, arr[3];

    cin >> cases;

    arr[0] = 0, arr[1] = 0, arr[2] = 0;

    for(int i=0; i<cases; i++){
        int a,b,c;

        cin >> a >> b >> c;
        arr[0] += a; arr[1] += b; arr[2] += c;
    }

    if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) { cout << "YES" << endl; }
    else { cout << "NO" << endl; }

    return 0;
}