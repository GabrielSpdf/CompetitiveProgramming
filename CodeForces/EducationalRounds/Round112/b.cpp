// Unsolved yet

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

struct Rec{
	ll x1, y1, x2, y2;
	ll area(){
		return((x2-x1)*(y2-y1));
	}
};

ll intersect(Rec p, Rec q){
	ll widht = max(min(p.x2, q.x2)-min(p.x1, q.x1), 0LL);
	ll length = max(min(p.y2, q.y2)-min(p.y1, q.y1), 0LL);

	return widht*length;
}

double dst(ll px1, ll py1, ll px2, ll py2){ 
	return sqrtl(((px1-px2)*(px1-px2))+((py1-py2)*(py1-py2)));
}

void solve(){
	ll rw, rh;
	cin >> rw >> rh;
	Rec t;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
	ll w, h;
	cin >> w >> h;
	
	ll width = t.x2 - t.x1;
	ll length = t.y2 - t.y1;
	if(width + w > rw && length + h > rh){ cout << -1 << "\n"; return; }

	bool left=false, right=false, top=false, bottom=false;
	if(abs(t.x1-0)<(rw-t.x2)){ // mais perto da esquerda
		right=true;	
	}
	else left=true;
	if(abs(t.y1-0)<(rh-t.y2)){ 
		top=true;
	}
	else bottom=true;
	
	Rec b;
	if(left){
		b.x1=0;
		b.x2=0+w;
	}
	else if(right){
		b.x1=rw-w;
		b.x2=rw;
	}

	if(bottom){
		b.y1=0;
		b.y2=0+h;
	}
	else if(top){
		b.y1=rh-h;
		b.y2=rh;
	}

	if(!intersect(t, b)){ cout << 0 << "\n"; return; }

	/* cerr << "top: " << top << "\n"; */
	/* cerr << "left: " << left << "\n"; */
	/* cerr << "right: " << right << "\n"; */
	/* cerr << "bottom: " << bottom << "\n"; */
	cerr << b.x1 << " " << b.y1 << " " << b.x2 << " " << b.y2 << "\n";
	
	double dist;
	if(left && bottom) dist = dst(b.x2, b.y2, t.x1, t.y1);
	else if(left && top) dist = dst(b.x2, b.y1, t.x1, t.y2);
	else if(right && bottom) dist =  dst(b.x1, b.y2, t.x2, t.y1);
	else if(right && top) dist = dst(b.x1, b.y1, t.x2, t.y2);
	
	cerr << "w: " << w << " | width: " << width << " | rw: " << rw << "\n";
	if(w+width<=rw){ dist = min(min(dist, max(double(b.x2-t.x1), 0.0)), max(double(t.x2-b.x1), 0.0)); cerr << "entrou1\n"; }
	if(h+length<=rh){ dist = min(min(dist, max(double(b.y2-t.y1), 0.0)), max(double(t.y2-b.y1), 0.0)); cerr << "entrou2\n"; }
	
	/* cerr << dst(b.x2, b.y2, t.x1, t.y1) << "\n"; */
	/* cerr << double(b.y2-t.y1) << "\n"; */
	/* cerr << double(b.x2-t.x1) << "\n"; */
	cout << dist << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
