#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200010;
const int INF = 4e18;

struct Node {
	int mn_val;
	int mx_val;
	int lazy_add;
};

Node t[4*MAXN];
int init_D[MAXN];

Node merge(const Node& a, const Node& b){
	Node result;
	result.mn_val = min(a.mn_val, b.mn_val);
	result.mx_val = max(a.mx_val, b.mx_val);
	result.lazy_add = 0;
	return result;
}

void push(int v){
	if(t[v].lazy_add!=0){
		// att filhos
		t[v*2].mn_val += t[v].lazy_add;
		t[v*2].mx_val += t[v].lazy_add;
		t[v*2].lazy_add += t[v].lazy_add;
		t[(v*2)+1].mn_val += t[v].lazy_add;
		t[(v*2)+1].mx_val += t[v].lazy_add;
		t[(v*2)+1].lazy_add += t[v].lazy_add;
		// limpa pai
		t[v].lazy_add = 0;
	}
}

void build(int a[], int v, int tl, int tr) {
	// base cp alg
    if (tl == tr) {
        t[v].mn_val = a[tl];
        t[v].mx_val = a[tl];
        t[v].lazy_add = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = merge(t[v*2], t[(v*2)+1]);
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
		//!!!
        t[v].mn_val += add;
        t[v].mx_val += add;
        t[v].lazy_add += add;
    } else {
		push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        t[v] = merge(t[v*2], t[(v*2)+1]);
    }
}

pair<int, int> query(int v, int tl, int tr){
	if(t[v].mn_val>=0){
		return {-INF, t[v].mn_val};
	}
	if(t[v].mx_val<0){
		return {t[v].mx_val, INF};
	}

	push(v);
	int tm = (tl + tr) / 2;
	pair<int, int> left_res = query(v*2, tl, tm);
	pair<int, int> right_res = query((v*2)+1, tm+1, tr);

	return {max(left_res.first, right_res.first), min(left_res.second, right_res.second)};
}

void solve(){
	int n;
	cin >> n;
	vector<int> travels(n);
	for(int i=0; i<n-1; i++){
		cin >> travels[i];
	}

	//--
	vector<int> P(n, 0);
	P[0] = travels[0];
	for(int i=1; i<n-1; i++){
		P[i] = P[i-1] + travels[i];
	}

	int T = P[n-2];
	for(int i=0; i<n-1; i++){
		init_D[i] = 2*P[i]-T;
	}

	build(init_D, 1, 0, n-2);
	//--
	
	int k;
	cin >> k;
	for(int i=0; i<=k; i++){
		int ans = abs(-T); // est 1
		ans = min(ans, abs(T)); // est N
	
		pair<int, int> best = query(1, 0, n-2);

		if(best.first > -INF){
			ans = min(ans, abs(best.first));
		}
		if(best.second < INF){
			ans = min(ans, abs(best.second));
		}

		cout << ans << "\n";
		if(i<k){
			int j;
			int new_t;
			cin >> j >> new_t;
			j--; // 0-idx
			
			int delta = new_t - travels[j];
			travels[j] = new_t;

			update(1, 0, n-2, 0, j-1, -delta);
			update(1, 0, n-2, j, n-2, delta);

			T+=delta;
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	solve();

	return 0;
}

