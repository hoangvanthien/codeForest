#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
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
#define LAST(x) (int)x.size()-1

const int N = 1002;
const int K = 21;
int level[N], anc[K][N], Root;

int getLevel(int u) {
    if (u == Root) return level[u] = 1;
    if (level[u]) return level[u];
    return level[u] = getLevel(anc[0][u]) + 1;
}
int lca(int x, int y) {
    DFOR(k,20,0) if (level[anc[k][x]] >= level[y]) { x = anc[k][x]; }
    DFOR(k,20,0) if (level[anc[k][y]] >= level[x]) { y = anc[k][y]; }
    DFOR(k,20,0) if (anc[k][x] != anc[k][y]) {x = anc[k][x]; y = anc[k][y]; }
    while (x != y) {x = anc[0][x]; y = anc[0][y];}
    return x;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T,n,q;
	scanf("%d", &T);
	FOR(cnt,1,T) {
        scanf("%d", &n);
        FOR(i,1,n) anc[0][i] = level[i] = 0;
        int x,y;
        FOR(i,1,n) {
            scanf("%d", &x);
            FOR(j,1,x) scanf("%d", &y), anc[0][y] = i;
        }
        FOR(i,1,n) if (anc[0][y] == 0) Root = i;
        anc[0][Root] = Root;
        FOR(k,1,20) FOR(i,1,n) anc[k][i] = anc[k-1][anc[k-1][i]];
        FOR(i,1,n) getLevel(i);
        printf("Case %d:\n", cnt);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", lca(x,y));
        }
	}
}
