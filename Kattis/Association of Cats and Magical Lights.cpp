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

const int N = 300005;
const int oo = 1000000007;

int n, cntq, a[N];
II seg[N];
pair<LL, LL> T[N * 4];
vector<int> dsk[N], v;

void dfs(int u) {
    v.pb(u);
    seg[u].F = (int) v.size() - 1;
    forit(it, dsk[u]) dfs(*it);
    seg[u].S = (int) v.size() - 1;
}

void update(int node, int l, int r, int i, int color) {
    if (i < l || i > r) return;
    if (l == r) {
        if (color < 50) T[node].F ^= 1LL << color;
        else T[node].S ^= 1LL << (color - 50);
        return;
    }
    int mid = (l + r) / 2;
    update(lc, l, mid, i, color);
    update(rc, mid + 1, r, i, color);
    T[node].F = T[lc].F ^ T[rc].F;
    T[node].S = T[lc].S ^ T[rc].S;
}

pair<LL, LL> getVal(int node, int l, int r, int i, int j) {
    if (i > r || j < l) return mp(0LL, 0LL);
    if (i <= l && r <= j) return T[node];
    int mid = (l + r) / 2;
    pair<LL, LL> p1 = getVal(lc, l, mid, i, j), p2 = getVal(rc, mid + 1, r, i, j);
    return mp(p1.F ^ p2.F, p1.S ^ p2.S);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, cntq);
    sca(a, n);
    f1(i, n) a[i]--;
    f1(i, n - 1) {
        scni(p);
        dsk[p].pb(i + 1);
    }
    v.pb(0);
    dfs(1);
    f1(i, n) update(1, 1, n, i, a[v[i]]);
    f1(_, cntq) {
        scnii(x, y);
        if (x == 0) {
            pair<LL, LL> res = getVal(1, 1, n, seg[y].F, seg[y].S);
            printf("%d\n", (int) __builtin_popcountll(res.F) + (int) __builtin_popcountll(res.S));
        } else {
            --x;
            update(1, 1, n, seg[y].F, x);
            update(1, 1, n, seg[y].F, a[y]);
            a[y] = x;
        }
    }
}