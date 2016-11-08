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


const int N = 5002;
const int K = 21;

int n, ord[N], depth[N], fa[N], rmq[N][20], ind;
vector<int> dsk[N];
bool notRoot[N];

void dfs(int u, int d) {
    ord[ind] = u;
    fa[u] = ind;
    depth[ind++] = d;
    forit(it, dsk[u]) {
        int v = *it;
        dfs(v, d + 1);
        ord[ind] = u;
        depth[ind++] = d;
    }
}

int RMQ(int i, int j) {
    if (i > j) swap(i, j);
    int len = (int) (log(j - i + 1) / log(2));
    if (depth[rmq[i][len]] < depth[rmq[j - (1 << len) + 1][len]])
        return rmq[i][len];
    else
        return rmq[j - (1 << len) + 1][len];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif // ONLINE_JUDGE
    int T, q;
    scanf("%d", &T);
    FOR(cnt, 1, T) {
        scanf("%d", &n);
        f1(i, n) dsk[i].clear();
        memset(notRoot, 0, sizeof notRoot);
        f1(i, n) {
            scni(x);
            f1(j, x) {
                scni(y);
                dsk[i].pb(y);
                notRoot[y] = true;
            }
        }
        memset(ord, 0, sizeof ord);
        memset(depth, 0, sizeof depth);
        memset(fa, 0, sizeof fa);
        memset(rmq, 0, sizeof rmq);
        ind = 0;
        f1(i, n) if (!notRoot[i]) {
                dfs(i, 1);
                break;
            }
        f1(i, ind) rmq[i][0] = i;
        for (int k = 1; (1 << k) <= ind; ++k)
            for (int i = 1; i + (1 << k) - 1 <= ind; ++i) {
                if (depth[rmq[i][k - 1]] < depth[rmq[i + (1 << (k - 1))][k - 1]])
                    rmq[i][k] = rmq[i][k - 1];
                else
                    rmq[i][k] = rmq[i + (1 << (k - 1))][k - 1];
            }
        printf("Case %d:\n", cnt);
        scanf("%d", &q);
        while (q--) {
            scnii(x, y);
            printf("%d\n", ord[RMQ(fa[x], fa[y])]);
        }
    }
}
