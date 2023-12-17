//Accepted

#include <bits/stdc++.h>

using namespace std;

bool isOdd(int n){
    if(n%2 == 0){ return true; }
    else{ return false; }
}

int main(){
    int arr[3][3], matrix[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> matrix[i][j];
            if(isOdd(matrix[i][j]) == true){ matrix[i][j] = 0; } else{ matrix[i][j] = 1; }
            arr[i][j] = 1;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j] == 1){
                if(arr[i][j] == 1){ arr[i][j] = 0; } else{ arr[i][j] = 1; }
                if(i+1 < 3){ if(arr[i+1][j] == 1){ arr[i+1][j] = 0; } else{ arr[i+1][j] = 1; } }
                if(i-1 >= 0){ if(arr[i-1][j] == 1){ arr[i-1][j] = 0; } else{ arr[i-1][j] = 1; } }
                if(j+1 < 3){ if(arr[i][j+1] == 1){ arr[i][j+1] = 0; } else{ arr[i][j+1] = 1; } }
                if(j-1 >= 0){ if(arr[i][j-1] == 1){ arr[i][j-1] = 0; } else{ arr[i][j-1] = 1; } }
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }


    return 0;
}