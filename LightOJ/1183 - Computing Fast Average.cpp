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

const int N = 100005;
const int oo = 1000000007;
int n, q;

struct iT {
    int sum, lazy;

    iT() { sum = 0, lazy = -1; }

    iT(int v, int l) { sum = v, lazy = l; }
} T[N * 4];

void lazyUpd(int node, int l, int r) {
    int mid = (l + r) / 2;
    int val = T[node].lazy;
    T[lc].sum = (mid - l + 1) * val;
    T[rc].sum = (r - mid) * val;
    T[lc].lazy = T[rc].lazy = val;
    T[node].lazy = -1;
}

void update(int node, int l, int r, int i, int j, int val) {
    if (l > r) return;
    if (i > r || l > j) return;
    if (i <= l && r <= j) {
        T[node].sum = (r - l + 1) * val;
        T[node].lazy = val;
        return;
    }
    if (T[node].lazy != -1) lazyUpd(node, l, r);
    int mid = (l + r) / 2;
    update(lc, l, mid, i, j, val);
    update(rc, mid + 1, r, i, j, val);
    T[node].sum = T[lc].sum + T[rc].sum;
}

int query(int node, int l, int r, int i, int j) {
    if (l > r) return 0;
    if (i > r || l > j) return 0;
    if (i <= l && r <= j) {
        return T[node].sum;
    }
    if (T[node].lazy != -1) lazyUpd(node, l, r);
    int mid = (l + r) / 2;
    return query(lc, l, mid, i, j) + query(rc, mid + 1, r, i, j);
}

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    f1(__, TT) {
        scii(n, q);
        f0(i, N * 4 - 1) T[i] = iT();
        printf("Case %d:\n", __);
        while (q--) {
            scni(type);
            if (type == 1) {
                scniii(i, j, v);
                ++i, ++j;
                update(1, 1, n, i, j, v);
            } else {
                scnii(i, j);
                ++i, ++j;
                int sum = query(1, 1, n, i, j);
                int len = j - i + 1;
                int G = gcd(sum, len);
                if (G == len || sum == 0) printf("%d\n", sum / len);
                else printf("%d/%d\n", sum / G, len / G);
            }
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}