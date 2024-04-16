//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int inp1, inp2;
        cin >> inp1 >> inp2;
        
        vector<int> arr(inp1);

        for(int j=0; j<inp1; j++){
            arr[j] = j+1;
        }


        //cout << "max: " << max << endl;

        int aux, max=inp1-inp2-1;
        for(int k=0; k<(inp1-inp2)/2; k++){
            aux = arr[k];
            arr[k] = arr[max];
            arr[max] = aux;
            max--;
        }

        for(int r=0; r<(int)arr.size(); r++){
            cout << arr[r] << " ";
        }
        cout << endl;
    }


    return 0;
}