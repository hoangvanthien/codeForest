#include <bits/stdc++.h>
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


const int N = 100002;
const int oo = 1000000007;
int n,m;
void initSet() {
    FOR(i,1,n) pset[i] = i;
}
int getSet(int u) {
    return pset[u] == u ? u : pset[u] = getSet(pset[u]);
}
bool isSameSet(int u, int v) {
    return getSet(pset[u]) == getSet(pset[v]);
}
bool uniteSet(int u, int v) {
    int _u = u, _v = v;
    u = getSet(u); v = getSet(v);
    if (isSameSet(u, v) && cntSet[u] + cntSet[v] != n) return false;
    pset[u] = v;
    select.pb({_u,_v});
    if (isSameSet(u, v) && cntSet[u] + cntSet[v] == n) return true;
    return false;
}
void visit(int u) {

    forit(it, dsk[u]) {

    }
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
        scanf("%d%d", &u, &v);
        e.pb({u, v});
	}
    forit(it, e) {
        int u = it->F, v = it->S;
        if (deg[u] == 2 || deg[v] == 2) break;
        if (uniteSet(u, v)) break;
    }
    forit(it, select) {
        int u = it->F, v = it->S;
        dsk[u].pb(v); dsk[v].pb(u);
    }
}

