#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Rect{
	int x1, y1, x2, y2;
};

void solve(){
	Rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	
	// Overcomplicated
	// Inicialmente, o pensamento foi de calcular a distancia entre os vertices mais distantes
	// so que como ambos os quadrados podem assumir diversas posicoes, voce tem que cobrir todos os casos
	// o que acaba usando em excesso o max() e o abs()
	// Inclusive, voce pode se confundir e errar no caso de borda onde o maior lado eh um lado de um dos quadrados
	/* int width = max(max(abs(b.x2-a.x1), abs(a.x2-b.x1)), max(a.x2-a.x1, b.x2-b.x1)); */
	/* int length = max(max(abs(b.y2-a.y1), abs(a.y2-b.y1)), max(a.y2-a.y1, b.y2-b.y1)); */
	/* int gside = max(width, length); */

	int left = min(a.x1, b.x1);
	int right = max(a.x2, b.x2);
	int bottom = min(a.y1, b.y1);
	int top = max(a.y2, b.y2);

	int widht = right-left;
	int length = top-bottom;
	int gside = max(widht, length);

	cout << gside*gside << "\n";
}

int main(){
	setIO("square");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
