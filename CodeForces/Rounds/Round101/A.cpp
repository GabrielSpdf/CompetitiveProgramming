//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2, s3;
    vector<int> arr(200, 0);

    cin >> s1 >> s2 >> s3;

    for(int k=0; k<(int)s3.size(); k++){
        arr[s3[k]]++;
    }

    for(int i=0; i<(int)s1.size(); i++){
        arr[s1[i]]--;
    }

    for(int j=0; j<(int)s2.size(); j++){
        arr[s2[j]]--;
    }

    for(int l=0; l<(int)arr.size(); l++){
        if(arr[l] != 0){ cout << "NO" << endl; return 0; }
    }

    cout << "YES" << endl;

    return 0;
}
