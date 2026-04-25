#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;


void solve(){
    int n;
    cin >> n;

    map<string, vector<string>> adj;
    map<string, bool> visited;

    for(int i=0; i<n; i++){
        string from, to;
        for(int j=0; j<3; j++){
            string inp;
            cin >> inp;
            transform(inp.begin(), inp.end(), inp.begin(), ::tolower);
            if(j==0) to = inp;
            if(j==2) from = inp;
            if(j!=1) visited[inp] = false;
        }
        adj[from].push_back(to);
    }   
    queue<string> q;
    map<string, int> distance;

    q.push("polycarp");
    while(!q.empty()){
        string s = q.front();
        q.pop();

        for(auto it : adj[s]){
            if(visited[it]) continue;
            visited[it] = true;
            distance[it] = distance[s]+1;
            q.push(it);
        }
    }

    int ans = 0;
    for(auto it : distance){
        if(it.second>ans) ans = it.second;
    }

    cout << ++ans << "\n";
}

int main(){
    solve();
    return 0;
}