#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define f0(i,right) for(int i = 0; i < (right); ++i)
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
#define III pair<int, II>
#define LL long long
#define lb lower_bound
#define ub upper_bound

vector<III> edge;
vector<II> Tree[maxN];
bool isTree[maxN];
int anc[21][maxN], flux[21][maxN], l[maxN], p[maxN], Root, n, m;

bool cmp(III a, III b) { return a.F > b.F; }
int getRoot(int u) { return (p[u] == u) ? u : p[u] = getRoot(p[u]); }
void Union(int u, int v) { p[getRoot(u)] = getRoot(v); }
int getLevel(int u) {
	if (u == Root) return l[u] = 1;
	if (l[u] == 0) return l[u] = getLevel(anc[0][u]) + 1;
	return l[u];
}

void init() {
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
		int u,v,_c;
		scanf("%d%d%d", &u, &v, &_c);
		edge.pb(III(_c, II(u, v)));
	}
	sort(edge.begin(), edge.end(), cmp);
	FOR(i,1,n) p[i] = i;
}

void kruskal() {
	int cnt = 0;
	f0(i,m) {
		int u = edge[i].S.F, v = edge[i].S.S;
		if (getRoot(u) == getRoot(v)) continue;
		Union(u, v);
		isTree[i] = 1;
		if (++cnt == n-1) break;
	}
}

void initTree() {
	Root = 1;
	FOR(i,1,n) FOR(k,0,20) flux[k][i] = oo;
	f0(i,m) if (isTree[i]) {
		int u = edge[i].S.F, v = edge[i].S.S;
		Tree[u].pb(mp(v,edge[i].F));
		Tree[v].pb(mp(u,edge[i].F));
	}
	queue<int> q; q.push(1);
	anc[0][1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		forit(it, Tree[u])
		if (anc[0][(*it).F] == 0) {
			anc[0][(*it).F] = u;
			flux[0][(*it).F] = (*it).S;
			q.push((*it).F);
		}
	}
	FOR(i,1,n) getLevel(i);
}

int getFlux(int x, int y) {
	int ans = oo;
	DFOR(k,20,0) if (l[anc[k][x]] >= l[y]) {
		// ancestor 2^k-th of node x is deeper than node y
		ans = min(ans, flux[k][x]);
		x = anc[k][x];
	}
	DFOR(k,20,0) if (l[anc[k][y]] >= l[x]) {
		ans = min(ans, flux[k][y]);
		y = anc[k][y];
	}
	DFOR(k,20,0) if (anc[k][x] != anc[k][y]) {
		ans = min(ans, flux[k][x]); ans = min(ans, flux[k][y]);
		x = anc[k][x]; y = anc[k][y];
	}
	while (x != y) {
		ans = min(ans, flux[0][x]); ans = min(ans, flux[0][y]);
		x = anc[0][x]; y = anc[0][y];
	}
	return ans;
}

int main() {
	freopen("upgranet.inp", "r", stdin);
	freopen("upgranet.out", "w", stdout);
	// #ifndef ONLINE_JUDGE
	// freopen("input.inp", "r", stdin);
	// #endif // ONLINE_JUDGE
	init();
	kruskal();
	initTree();
	FOR(k,1,20) FOR(i,1,n) {
		anc[k][i] = anc[k-1][anc[k-1][i]];
		flux[k][i] = min(flux[k-1][anc[k-1][i]], flux[k-1][i]);
	}
	LL res = 0;
	f0(i,m) if (!isTree[i]) {
		int cur_weight = edge[i].F;
		int TheMaxFlux = getFlux(edge[i].S.F, edge[i].S.S);
		res += TheMaxFlux - cur_weight;
	}
	printf("%lld", res);
}
