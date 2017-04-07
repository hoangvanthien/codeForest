#include "bits/stdc++.h"

using namespace std;

#define loop(i, x, y, b) for(int i = (x), b = ((x) <= (y)); b ? (i <= (y)) : (i >= (y)); i += b ? 1 : -1)
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
#define vi vector<int>
#define vii vector<II >

const int N = 2005;
const int oo = 1000000007;
int n, mark[N], f[N][3];
vi dsk[N];

void dfs(int u) {
    mark[u] = true;
    if (dsk[u].size() == 0) {
        f[u][0] = 1;
        f[u][1] = f[u][2] = oo;
        return;
    }
    f0(i, dsk[u].size()) {
        int v = dsk[u][i];
        if (mark[v]) {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
            continue;
        }
        dfs(v);
    }
    int tmp = 0, Min = oo;
    for (int v : dsk[u]) {
        f[u][0] += min(f[v][0], min(f[v][1], f[v][2]));
        f[u][2] += min(f[v][0], f[v][1]);
    }
    tmp = f[u][2];
    for (int v : dsk[u]) {
        minimize(Min, tmp - min(f[v][0], f[v][1]) + f[v][0]);
    }
    f[u][0]++;
    f[u][1] = Min;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (sci(n) && n) {
        f1(i, n) dsk[i].clear();
        memset(mark, 0, sizeof mark);
        memset(f, 0, sizeof f);
        f1(i, n - 1) {
            scnii(x, y);
            dsk[x].pb(y);
            dsk[y].pb(x);
        }
        dfs(1);
        printf("%d\n", min(f[1][0], f[1][1]));
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}