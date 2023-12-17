//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a,b,c,d;

    cin >> n;

    //1234
    n++;
    a = n%10; //4
    b = (n%100)/10; //3
    c = (n%1000)/100; //2
    d = n/1000; //1
 
    while(a==b || a==c || a==d || b==c || b==d || c==d){
        n++;
        a = n%10;
        b = (n%100)/10;
        c = (n%1000)/100;
        d = n/1000; 
    }

    cout << n << endl;

    return 0;
}