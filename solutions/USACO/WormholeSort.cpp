#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef pair<int, int> ii;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// esboco
// 1. verifica se a sequencia ta ordenada. se estiver, printa -1
// 2. caso nao estiver, veja as posicoes que tem que ser ordenada
// 3. veja os caminhos disponiveis ate a ordenacao completa, caso tiver mais de um, pega o maior
// duvida: como eu vejo todos os caminhos possiveis de um no ate outro? rodar uma bfs/dfs e marcar como visitado vai fazer com que eu nao ache outros caminhos na proxima iteracao
// analisar todos os caminhos possiveis? parece overkill
// ordenar o peso das arestas e verificar se eu consigo passar por ela comecando em tal no? ou ao contrario e ver se consigo nao passar pela menor?
// no geral, me parece que tenho que analisar diferentes caminhos e pegar aquele com o maior menor caminho, mas parece que a bfs/dfs tradicionais me bloqueiam de explorar todos os caminhos
// no fim, eh busca binaria na resposta usando o peso das arestas

vector<int> v, v_aux;
vector<vector<pair<int, int>>> listAdj;
vector<int> component;

void dfs(int src, int id_c, int min_w){
    component[src] = id_c;

    for(auto adj : listAdj[src]){
        int u = adj.first;
        int w = adj.second;

        if(component[u] != -1 || w < min_w) continue;
        dfs(u, id_c, min_w);
    }
}

bool check(int min_w){
    int n = (int)v.size();
    component.assign(n, -1);
    int id_c = 0;

    for(int i=0; i<n; i++){
        if(component[i] == -1){
            dfs(i, id_c, min_w);
            id_c++;
        }
    }

    for(int i=0; i<n; i++){
        if(component[v_aux[i]] != component[v[i]]) return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    v.resize(n);
    listAdj.assign(n, vector<pair<int, int>>());

    for(auto &a: v){
        cin >> a;
        a--;
    }
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        listAdj[a].push_back({b, c});
        listAdj[b].push_back({a, c});
    }

    v_aux = v;
    sort(v_aux.begin(), v_aux.end());

    if(v_aux == v){
        cout << -1 << "\n";
        return;
    }

    int l=1, r=1e9;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << l-1 << "\n";
}

signed main(){
	setIO("wormsort");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

    return 0;
}
