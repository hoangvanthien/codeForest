
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound

const int N = 100005;


struct Rect {
	int x,y,u,v;
	bool operator < (const Rect &b) const {
		pair<II, II> hcn1 = mp(mp(x,y), mp(u,v)), hcn2 = mp(mp(b.x, b.y), mp(b.u, b.v));
		return hcn1 < hcn2;
	}
};
Rect rect[N];
int n;

Rect mr(int _x, int _y, int _u, int _v) {
	Rect res;
	res.x = _x; res.y = _y; res.u = _u; res.v = _v;
	return res;
}

bool chong(Rect A, Rect B) {
	if (A.x < B.u && A.y < B.v && A.u > B.x && A.v > B.y) return true;
	else return false;
}

LL getStep(Rect A, Rect B) {
	int x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y;
	int t1 = abs(x1-x2), t2 = abs(y1-y2);
	return (LL)abs(t1-t2)+min(t1,t2);
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d", &n);
	FOR(i,1,n) {
		int _x,_y,_u,_v;
		scanf("%d%d%d%d", &_x, &_y, &_u, &_v);
		rect[i] = mr(_x,_y,_u,_v);
	}
	sort(rect+1, rect+1+n);
	int k = (n+1)/2;
	LL ans = max(getStep(rect[1], rect[k]), getStep(rect[k], rect[n]));
	printf("%lld", ans);
}
