// RM
// Kattis Ski = GSS (SPOJ) + Binary Search + BIT
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

const int N = 500005;
const LL oo = 9000000000000000007LL;

struct Vertex {
    LL suf, pre, mid, all;

    Vertex() { }

    Vertex(LL s, LL p, LL m, LL a) {
        suf = s, pre = p, mid = m, all = a;
    }
};

int n, cq, cabinPos;
LL bit[N], fun[N], h[N], cost[N];
Vertex T[N * 4];

void init(int node, int l, int r) {
    if (l == r) {
        T[node].suf = T[node].pre = T[node].mid = T[node].all = fun[l];
        return;
    }
    int mid = (l + r) / 2;
    init(lc, l, mid), init(rc, mid + 1, r);
    T[node].pre = max(T[lc].pre, T[lc].all + T[rc].pre);
    T[node].suf = max(T[rc].suf, T[lc].suf + T[rc].all);
    T[node].mid = max(T[lc].mid, max(T[rc].mid, T[lc].suf + T[rc].pre));
    T[node].all = T[lc].all + T[rc].all;
}

void update(int node, int l, int r, int i) {
    if (i < l || i > r) return;
    if (l == r) {
        T[node].suf = T[node].pre = T[node].mid = T[node].all = fun[i];
        return;
    }
    int mid = (l + r) / 2;
    update(lc, l, mid, i), update(rc, mid + 1, r, i);
    T[node].pre = max(T[lc].pre, T[lc].all + T[rc].pre);
    T[node].suf = max(T[rc].suf, T[lc].suf + T[rc].all);
    T[node].mid = max(T[lc].mid, max(T[rc].mid, T[lc].suf + T[rc].pre));
    T[node].all = T[lc].all + T[rc].all;
}

Vertex query(int node, int l, int r, int i, int j) {
    if (i > r || j < l) return Vertex(-oo, -oo, -oo, 0LL);
    if (i <= l && r <= j) return T[node];
    int mid = (l + r) / 2;
    Vertex v1 = query(lc, l, mid, i, j), v2 = query(rc, mid + 1, r, i, j), res;
    res.pre = max(v1.pre, v1.all + v2.pre);
    res.suf = max(v2.suf, v1.suf + v2.all);
    res.mid = max(v1.mid, max(v2.mid, v1.suf + v2.pre));
    res.all = v1.all + v2.all;
    return res;
}

void updateBIT(int i, LL val) {
    while (i <= n) {
        bit[i] += val;
        i += i & (-i);
    }
}

LL getSum(int i) {
    LL sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

int rightMost(LL money) {
    int l = 0, r = n - cabinPos, res = cabinPos;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (getSum(cabinPos + mid) - getSum(cabinPos) > money) r = mid - 1;
        else {
            l = mid + 1;
            res = cabinPos + mid;
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, cq);
    f0(i, n + 1) scanf("%lld", &h[i]);
    f0(i, n) {
        cost[i + 1] = h[i] + h[i + 1];
        updateBIT(i + 1, cost[i + 1]);
    }
    f0(i, n) {
        fun[i + 1] = (h[i] - h[i + 1]) * (h[i] - h[i + 1]);
        if (h[i] < h[i + 1]) fun[i + 1] = -fun[i + 1];
    }
    init(1, 1, n);
    while (cq--) {
        scni(type);
        if (type == 0) {
            scnii(i, newHeight);
            h[i] = newHeight;
            if (i > 0) {
                LL old = cost[i];
                cost[i] = h[i - 1] + h[i];
                updateBIT(i, cost[i] - old);
                fun[i] = (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
                if (h[i - 1] < h[i]) fun[i] *= -1;
                update(1, 1, n, i);
            }
            if (i < n) {
                LL old = cost[i + 1];
                cost[i + 1] = h[i] + h[i + 1];
                updateBIT(i + 1, cost[i + 1] - old);
                fun[i + 1] = (h[i] - h[i + 1]) * (h[i] - h[i + 1]);
                if (h[i] < h[i + 1]) fun[i + 1] *= -1;
                update(1, 1, n, i + 1);
            }
        } else {
            LL money;
            scanf("%d %lld", &cabinPos, &money);
            int RM = rightMost(money);
            if (RM >= 1) printf("%lld\n", max(query(1, 1, n, 1, RM).mid, 0LL));
            else puts("0");
        }

    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}