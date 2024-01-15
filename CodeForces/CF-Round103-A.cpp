//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, inp, maior=0, menor=101, cont=0, imax=-1, imin=-1, ver=0;
    cin >> n;
    vector<int> sol;

    for(int i=0; i<n; i++){
        cin >> inp;
        if(inp > maior){ maior = inp; }
        if(inp < menor){ menor = inp; }
        sol.push_back(inp);
    }

    for(int j=0; j<(int)sol.size(); j++){
        if(sol[j]==maior && maior!= sol[0] && ver==0){ imax=j; ver=1; }
        if(sol[j]==menor && menor!= sol[sol.size()-1]){ imin=j; }
    }

    if(imax!=-1 && imin==-1){ cont+=imax; }
    if(imax==-1 && imin!=-1){ cont+=((sol.size()-1) - imin); }
    if(imax < imin && imax!=-1 && imin!=-1){ cont+=(imax + (sol.size()-1) - imin); }
    if(imax > imin && imax!=-1 && imin!=-1){ cont+=(imax + (sol.size()-1) - imin - 1); }

    cout << cont << endl;


    return 0;
}