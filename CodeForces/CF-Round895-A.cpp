//Accepted

#include <bits/stdc++.h>
    
using namespace std;
    
int main(void){
    int t,a,b,c, aux;
    
    cin >> t;
    for(int i=0; i<t; i++){
    aux=0;
    cin >> a >> b >> c;
    while(a!=b){
        if(abs(a-b) <= c) {aux++; break;}
        if(a>b) {a-=c; b+=c; aux++; if(a<b) break;}
        else if(a<b) {a+=c; b-=c; aux++; if(a>b) break;}
        
    }
    cout << aux << endl;
    }
    
    return 0;
}