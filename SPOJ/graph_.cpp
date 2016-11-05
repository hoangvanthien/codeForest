// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define pb push_back
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define scii(a, b) scanf("%d%d", &a, &b)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)

const int N = 200005;
const int oo = 1000000007;
int n, m, num[N], low[N], par[N], cutVertex[N], bridge;
vector<int> dsk[N];
int ___cnt, root, child;

void dfs(int u) {
    num[u] = low[u] = ++___cnt;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            if (u == root) ++child;
            par[v] = u;
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] >= num[u]) cutVertex[u] = true;
            if (low[v] > num[u]) ++bridge;
        } else if (par[u] != v) {
            minimize(low[u], num[v]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, m);
    f1(i, m) {
        scnii(x, y);
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    FOR(i, 1, n) if (num[i] == 0) {
            root = i;
            child = 0;
            dfs(i);
            cutVertex[i] = child > 1;
        }
    int cnt = 0;
    f1(i, n) if (cutVertex[i]) ++cnt;
    printf("%d %d\n", cnt, bridge);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}