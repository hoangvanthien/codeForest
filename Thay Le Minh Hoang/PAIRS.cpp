
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
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

set<int> root;
int pSet[maxN], cntSet[maxN], n, m;

void initSet() {
	FOR(i,1,n) pSet[i] = i, cntSet[i] = 1;
}
inline int getRoot(int u) {
	return pSet[u] = (pSet[u] == u) ? u : getRoot(pSet[u]);
}
int isSameSet(int u, int v) {
	return getRoot(u) == getRoot(v);
}
inline void unionSet(int u, int v) {
	int x = getRoot(u), y = getRoot(v);
	if (x == y) return;
	pSet[y] = x;
	cntSet[x] += cntSet[y];
}

int main() {
	freopen("pairs.inp", "r", stdin);
	freopen("pairs.out", "w", stdout);
	scanf("%d%d", &n, &m);
	initSet();
	LL ans = 0;
	FOR(i,1,m) {
		int u,v;
		scanf("%d%d", &u, &v);
		if (!isSameSet(u, v))
		ans += (LL)cntSet[pSet[u]] * cntSet[pSet[v]];
		unionSet(u, v);
		printf("%lld\n", ans);
	}
}
