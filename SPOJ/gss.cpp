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

const int N = 50005;
const LL oo = 1000000000000000007LL;

struct Vertex {
    LL suf, pre, mid, all;

    Vertex() { suf = pre = mid = -oo, all = 0; }
};

int n, a[N], cq;
Vertex T[N * 4];

void init(int node, int l, int r) {
    if (l == r) {
        T[node].suf = T[node].pre = T[node].mid = T[node].all = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(lc, l, mid), init(rc, mid + 1, r);
    T[node].pre = max(T[lc].pre, T[lc].all + T[rc].pre);
    T[node].suf = max(T[rc].suf, T[lc].suf + T[rc].all);
    T[node].mid = max(T[lc].mid, max(T[rc].mid, T[lc].suf + T[rc].pre));
    T[node].all = T[lc].all + T[rc].all;
}

Vertex query(int node, int l, int r, int i, int j) {
    if (i > r || j < l) return Vertex();
    if (i <= l && r <= j) return T[node];
    int mid = (l + r) / 2;
    Vertex v1 = query(lc, l, mid, i, j), v2 = query(rc, mid + 1, r, i, j), res;
    res.pre = max(v1.pre, v1.all + v2.pre);
    res.suf = max(v2.suf, v1.suf + v2.all);
    res.mid = max(v1.mid, max(v2.mid, v1.suf + v2.pre));
    res.all = v1.all + v2.all;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    init(1, 1, n);
    sci(cq);
    while (cq--) {
        scnii(x, y);
        printf("%lld\n", query(1, 1, n, x, y).mid);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}