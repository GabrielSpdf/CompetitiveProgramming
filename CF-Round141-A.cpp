//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, cont=0;
    vector<int> arr;

    for(int i=0; i<4; i++){
        cin >> a;
        arr.push_back(a);
    }

    int k=(int)arr.size()-1;

    for(int j=0; j<(int)arr.size()-1; j++){
        if(arr[k]==arr[j]){ cont++; arr.pop_back(); k=(int)arr.size()-1; j=-1; }
        if(j == (int)arr.size()-2 && k > 0){ arr.pop_back(); k=(int)arr.size()-1; j=-1; }
    }

    cout << cont << endl;

    return 0;
}