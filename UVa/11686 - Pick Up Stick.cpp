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

const int N = 1000005;
const int oo = 1000000007;
int n, m, mark[N], indeg[N], inStack[N];
bool cycle;
vector<int> dsk[N], topo;

void dfs(int u) {
    mark[u] = true;
    inStack[u] = true;
    forit(it, dsk[u])
        if (!mark[*it]) dfs(*it);
        else if (inStack[*it]) cycle = true;
    inStack[u] = false;
    topo.pb(u);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~scii(n, m)) {
        if (n == 0 && m == 0) break;
        memset(indeg, 0, sizeof indeg);
        memset(mark, 0, sizeof mark);
        memset(inStack, 0, sizeof inStack);
        topo.clear();
        f1(i, n) dsk[i].clear();
        f1(_, m) {
            scnii(x, y);
            dsk[x].pb(y);
            indeg[y]++;
        }
        cycle = false;
        f1(i, n) if (indeg[i] == 0) dfs(i);
        if (cycle) {
            puts("IMPOSSIBLE");
            continue;
        }
        if ((int) topo.size() == n) forrit(it, topo) printf("%d\n", *it);
        else puts("IMPOSSIBLE");
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}