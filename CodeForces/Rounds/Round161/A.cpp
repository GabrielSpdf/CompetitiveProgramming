//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int matrix[5][5], ci, cj;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> matrix[i][j]; 
            if(matrix[i][j] != 0){ ci=i; cj=j; }
        }
    }

    cout << abs(ci-2) + abs(cj-2) << endl;


    return 0;
}