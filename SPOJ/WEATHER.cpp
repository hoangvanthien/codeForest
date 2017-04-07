#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define minimize(x, y) x=min(x,(y))
#define scii(a, b) scanf("%d%d", &a, &b)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)

const int N = 105;
const int oo = 1000000007;
int n, m, num[N], low[N], cntDFS, sz[N];
vector<int> dsk[N];
vector<pair<int, int> > br;

void dfs(int p, int u) {
    sz[u] = 1;
    num[u] = low[u] = ++cntDFS;
    for (int v : dsk[u]) {
        if (v == p) {
            p = 0;
            continue;
        }
        if (!num[v]) {
            dfs(u, v);
            sz[u] += sz[v];
            minimize(low[u], low[v]);
            if (low[v] > num[u]) br.pb(mp(u, v));
        } else
            minimize(low[u], num[v]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, m);
    f1(i, m) {
        scnii(x, y);
        dsk[x].pb(y), dsk[y].pb(x);
    }
    dfs(0, 1);
    int ans = 0;
    forit(it, br) {
        int u = it->F, v = it->S;
        ans += sz[v] * (n - sz[v]);
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}