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

const int N = 100005;
const int oo = 1000000007;
int n, m, n1, n2, num[N], low[N], parent[N], cntDFS, sa[N], sb[N], mark[N];
bool isa[N], isb[N];
vector<int> dsk[N];
vector<II > bridge;

void dfs(int u) {
    num[u] = low[u] = ++cntDFS;
    forit(it, dsk[u]) {
        int v = *it;
        if (parent[u] == v) {
            parent[u] = 0;
            continue;
        }
        if (!num[v]) {
            parent[v] = u;
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) bridge.pb(mp(u, v));
        } else
            minimize(low[u], num[v]);
    }
}

void dfs2(int u) {
    mark[u] = true;
    if (isa[u]) sa[u]++;
    if (isb[u]) sb[u]++;
    forit(it, dsk[u]) {
        if (!mark[*it]) {
            dfs2(*it);
            sa[u] += sa[*it];
            sb[u] += sb[*it];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("net.inp", "r", stdin);
    // freopen("input.inp", "r", stdin);
   freopen("net.out", "w", stdout);
#endif // ONLINE_JUDGE
    sciiii(n, m, n1, n2);
    f1(i, n1) {
        scni(x);
        isa[x] = true;
    }
    f1(i, n2) {
        scni(x);
        isb[x] = true;
    }
    f1(i, m) {
        scnii(x, y);
        dsk[x].pb(y), dsk[y].pb(x);
    }
    dfs(1);
    dfs2(1);
    int ans = 0;
    forit(it, bridge) {
        int u = it->F, v = it->S;
        if (sa[v] == 0 || sa[v] == n1 || sb[v] == 0 || sb[v] == n2) ++ans;
    }
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}