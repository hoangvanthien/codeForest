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

const int N = 10005;
const int oo = 1000000007;
int cntDFS, m, n, num[N], low[N], child, root, par[N], cut[N];
vector<int> dsk[N];

void dfs(int u) {
    num[u] = low[u] = ++cntDFS;
    forit(it, dsk[u]) {
        int v = *it;
        if (v == par[u]) {
            par[u] = 0;
            continue;
        }
        if (num[v] == 0) {
            par[v] = u;
            if (root == u) ++child;
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] >= num[u]) cut[u] = true;
        } else
            minimize(low[u], num[v]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~scii(n, m)) {
        if (n == 0 && m == 0) break;
        memset(num, 0, sizeof num);
        memset(low, 0, sizeof low);
        memset(par, 0, sizeof par);
        memset(cut, 0, sizeof cut);
        child = 0;
        cntDFS = 0;
        f1(i, n) dsk[i].clear();

        f1(i, m) {
            scnii(x, y);
            dsk[x].pb(y);
            dsk[y].pb(x);
        }
        root = 1;
        dfs(1);
        cut[1] = child > 1;
        int ans = 0;
        f1(i, n) ans += cut[i];
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}