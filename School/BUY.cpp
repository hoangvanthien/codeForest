#include "bits/stdc++.h"
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 12;
const int oo = 1000000007;

int judge[9][9] = {
	{0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1},
	{0,1,2,2,2,3,3,3,3},
	{0,1,2,3,3,3,4,4,4},
	{0,1,2,3,4,4,5,5,5},
	{0,2,3,3,4,5,5,6,6},
	{0,2,3,4,5,5,6,7,8},
	{0,2,3,4,5,6,7,7,8},
	{0,2,3,4,5,6,8,8,8}
};

struct Tank {
	int b,c,p,ind;
	double v;
	bool operator < (const Tank & B) const {
		if (v < B.v) return true;
		if (v == B.v) return c < B.c;
		return false;
	}
	void print() {
		printf("%d %d %d %.0f %d\n", b, c, p, v, ind);
	}
};

Tank tank[N];
int ans[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	//	freopen("buy.out", "w", stdout);
#endif // ONLINE_JUDGE
	int n = 10;
	FOR(i,1,n) scanf("%d %d %d", &tank[i].b, &tank[i].c, &tank[i].p), tank[i].ind = i;
	FOR(i,1,n) tank[i].v = judge[tank[i].b][tank[i].c];
	sort(tank+1, tank+1+n);
	reverse(tank+1, tank+1+n);
	//	FOR(i,1,n) tank[i].print();
	int sum = 0;
	FOR(i,1,n) if (sum + tank[i].p <= 100) {
		ans[tank[i].ind] = 1;
		sum += tank[i].p;
	} else {
		ans[tank[i].ind] = 0;
	}
	FOR(i,1,n) printf("%d\n", ans[i]);
}
