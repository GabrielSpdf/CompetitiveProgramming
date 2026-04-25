<<<<<<< HEAD
//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, outp;


    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == '.'){ outp.append(to_string(0)); }
        if(s[i] == '-' && s[i+1] == '.' && i+1<=(int)s.size()){ outp.append(to_string(1)); i++; }
        if(s[i] == '-' && s[i+1] == '-' && i+1<=(int)s.size()){ outp.append(to_string(2)); i++; }
    }

    cout << outp << endl;

    return 0;
}
=======
//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, outp;


    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == '.'){ outp.append(to_string(0)); }
        if(s[i] == '-' && s[i+1] == '.' && i+1<=(int)s.size()){ outp.append(to_string(1)); i++; }
        if(s[i] == '-' && s[i+1] == '-' && i+1<=(int)s.size()){ outp.append(to_string(2)); i++; }
    }

    cout << outp << endl;

    return 0;
}
>>>>>>> 6a21941374c2cd2aacb844e7ec65f58fb30c24f1
