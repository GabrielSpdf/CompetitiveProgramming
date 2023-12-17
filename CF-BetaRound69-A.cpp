//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    vector<int> prime;
    prime.push_back(2); prime.push_back(3); prime.push_back(5); prime.push_back(7);

    for(int i=8; i<=50; i++){
        if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0){ prime.push_back(i); }
    }

    for(int j=0; j<(int)prime.size(); j++){
        if(prime[j] == a){ if(prime[j+1] == b) { cout << "YES" << endl; break; } else{ cout << "NO" << endl; break; } }
    }

    return 0;
}