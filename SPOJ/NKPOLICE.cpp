// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scni(i) int i; scanf("%d",&i)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)
#define scniiii(a, b, c, d) int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1
#define MP(x, y) mp(min(x,y), max(x,y))
#define lt2(x) (1 << (x))

const int N = 100005;
const int oo = 1000000007;

int n, m, num[N], low[N], par[N], cntDFS, cntChild;
vector<int> dsk[N], child[N];
int mark[N], ord[N * 2], fa[N * 2], depth[N * 2], ind, f[N * 2][50], la[N * 2];
map<II, bool> br;

void dfs(int u) {
    num[u] = low[u] = ++cntDFS;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            child[u].pb(v);
            par[v] = u;
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) br[MP(u, v)] = true;
        } else if (v != par[u]) minimize(low[u], num[v]);
    }
}

void dfs2(int u, int d) {
    ord[ind] = u;
    fa[u] = ind;
    depth[ind++] = d;
    forit(it, child[u]) {
        dfs2(*it, d + 1);
        ord[ind] = u;
        depth[ind++] = d;
    }
}

void initRMQ() {
    f0(i, ind) f[i][0] = i;
    for (int k = 1; (1 << k) <= ind; ++k)
        for (int i = 0; i + (1 << k) - 1 < ind; ++i) {
            if (depth[f[i][k - 1]] < depth[f[i + (1 << (k - 1))][k - 1]])
                f[i][k] = f[i][k - 1];
            else
                f[i][k] = f[i + (1 << (k - 1))][k - 1];
        }
}

int RMQ(int i, int j) {
    if (i > j) swap(i, j);
    int len = (int) floor(log((double) j - i + 1) / log(2.0));
    if (depth[f[i][len]] < depth[f[j - (1 << len) + 1][len]])
        return f[i][len];
    else
        return f[j - (1 << len) + 1][len];
}

int LCA(int x, int y) {
//    printf("%d %d %d\n", x, y, ord[RMQ(fa[x], fa[y])]);
    return ord[RMQ(fa[x], fa[y])];
}

bool isAnc(int P, int C) {
    return (LCA(P, C) == P);
}

int findRelative(int P, int C) {
    forit(it, child[P]) if (isAnc(P, *it) && isAnc(*it, C)) return *it;
}

int dist(int A, int B) {
    int temp = LCA(A, B);
    int res = depth[fa[A]] + depth[fa[B]] - depth[fa[LCA(A, B)]] * 2;
    return res;
}

int onTheWay(int A, int B, int M) {
    int AM = dist(A, M);
    int MB = dist(M, B);
    int AB = dist(A, B);
    return dist(A, M) + dist(M, B) == dist(A, B);
}

bool overTheBridge(int a, int b, int g1, int g2) {
//    if (isAnc(g2, g1)) swap(g1, g2);
    if (!br[MP(g1, g2)]) return true;
    return !(onTheWay(a, b, g1) && onTheWay(a, b, g2));
}

bool overTheCut(int a, int b, int c) {
    if (!isAnc(c, a) && !isAnc(c, b)) return true;
    if (isAnc(c, a) && isAnc(c, b)) {
        int e = findRelative(c, a), f = findRelative(c, b);
        if (e == f) return true;
        return (low[e] < num[c] && low[f] < num[c]);
    }
    if (isAnc(c, a)) swap(a, b);
    int e = findRelative(c, b);
    return low[e] < num[c];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, m);
    dsk[0].pb(1);
    child[0].pb(1);
    f1(i, m) {
        scnii(x, y);
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    dfs(1);
    memset(fa, -1, sizeof fa);
    dfs2(0, 0);
    initRMQ();
    scni(cntQuery);
    while (cntQuery--) {
        scni(type);

        if (type == 1) {
            scniiii(a, b, g1, g2);
            if (overTheBridge(a, b, g1, g2)) puts("yes");
            else puts("no");
        } else {
            scniii(a, b, c);
            if (overTheCut(a, b, c)) puts("yes");
            else puts("no");
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}