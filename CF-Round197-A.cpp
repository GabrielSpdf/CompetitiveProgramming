//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> sum;

    for(int i=0; i<(int)s.size(); i+=2){
        sum.push_back(s[i] - '0');
    }

    sort(sum.begin(), sum.end());

    for(int j=0; j<(int)sum.size(); j++){
        if(j==(int)sum.size()-1){ cout << sum[j]; }
        else{ cout << sum[j] << "+"; }
    }


    return 0;
}