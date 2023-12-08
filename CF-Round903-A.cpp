//Accepted

#include <bits/stdc++.h>

using namespace std;

int encontra_substring(string x, string s){
    size_t found = x.find(s);

    if(found != std::string::npos) { return 1; } //encontrou
    else{ return 0; }
}

int main(){

    int cases, n, m, qtd;
    string x, s;
    //x has length n and x has length m

    cin >> cases;

    for(int i=0; i<cases; i++){
        qtd = 0;
        cin >> n >> m;

        x.resize(n); s.resize(m);

        cin >> x >> s;

        for(int j=0; j<6; j++){ 
            if(encontra_substring(x, s)) { cout << qtd << endl; break;}
            x.append(x);
            qtd++;
            if(j==5) { cout << -1 << endl; }
        }
    }

    return 0;
}