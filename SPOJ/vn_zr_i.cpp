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

const int N = 35;
const int oo = 1000000007;

LL c[N][N];
int a[N];

inline LL nCr(int n, int r) {
    if (r < 0 || n < 0 || r > n) return 0;
    if (r == n || r == 0) return 1;
    if (c[n][r]) return c[n][r];
    return c[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

inline int len(int x) {
    if (x == 0) return 1;
    int res = 0;
    while (x) {
        ++res;
        x >>= 1;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int n, m;
    while (~scii(n, m)) {
        memset(a, 0, sizeof a);
        int l = len(n);
        DFOR(i, l - 1, 0) {
            a[i] = a[i + 1] + 1;
            if (n & (1 << i)) a[i]--;
        }
        LL ans = 0;
        f1(k, 31) {
            LL cnt = 0;
            f1(i, l - 1) cnt += nCr(i - 1, k);
            f0(i, l - 1) if (n & (1 << i)) {
                    cnt += nCr(i, k - a[i] - 1);
                }
            if (a[0] == k) ++cnt;
            ans += cnt * ((k - 1) / m + 1);
        }
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}