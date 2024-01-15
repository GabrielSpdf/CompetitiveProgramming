//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, aux, ver, comp1, comp2;
    cin >> n;
    string s, s1, s2;

    for(int i=0; i<n; i++){
        cin >> s;

        ver=0; 

        aux = (int)s.size()/2;
        
        while(ver!=-1){
            string s1, s2;

            if(aux<1){ cout << -1 << endl; break; }
            if(s[0] == '0'){ cout << -1 << endl; break; }

            for(int j=0; j<aux; j++){
                s1.append(to_string(s[j] - '0'));
            } 

            for(int k=aux; k<(int)s.size(); k++){
                s2.append(to_string(s[k] - '0'));
            }

            //cout << "s1: " << s1 << endl;
            //cout << "s2: " << s2 << endl;
            
            comp1 = stoi(s1); comp2 = stoi(s2);

            //cout << "comp1: " << comp1 << endl;
            //cout << "comp2: " << comp2 << endl;

            //cout << "aux: " << aux << endl;

            if(comp1 < comp2 && comp1>0 && s2[0]!='0'){ ver=-1; cout << comp1 << " " << comp2 << endl; }
            if((comp1 >= comp2) || s2[0] == '0'){ aux--; }
        }

    }


    return 0;
}