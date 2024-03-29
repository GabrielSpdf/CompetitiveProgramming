//Accepted

#include <bits/stdc++.h>

using namespace std;

const unsigned long long MAX = 10e6;

typedef unsigned long long ull;

unsigned long long power(ull exp){
    ull result = 1;
    for(ull i=0; i<exp; ++i){
        result*=10;
    }
    return result;
}

bool is_p(ull v){
    ull cp = v, ver=0;
    while(v!=0){
        ver = ver*10 + v%10;
        v/=10;
    }

    return cp == ver;
}

int main(){
    ull n, k=0, x=1;
    vector<ull> v;
    v.push_back(1);

    cin >> n;
    while(k<=n){
        x++;
        k = x*x*x;
        //cout << "k: " << k << endl;
        if(is_p(k) && k<=n) v.push_back(k);
    }
    is_p(n);

    cout << v[v.size()-1] << endl;

    return 0;
}