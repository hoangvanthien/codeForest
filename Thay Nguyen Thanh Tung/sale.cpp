// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define LL long long
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

const int N = 200005;
const int oo = 1000000007;
int n, e, w, a[N];
LL f[N];

LL buy(int l, int r, int q) {
    if (l > r) return 0;
    if (r - l + 1 >= q + w) r -= w;
    return f[r] - f[l - 1] + e;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sciii(n, e, w);
    sca(a, n);
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    f1(i, n) f[i] = f[i - 1] + a[i];
    f1(q, n) {
        int l = 1;
        LL ans = buy(1, n, q), sum = 0;
        while (l <= n) {
            int r = min(l + q + w - 1, n);
            sum += buy(l, r, q);
            minimize(ans, sum + buy(r + 1, n, q));
            l = r + 1;
        }
        cout << ans << ' ';
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}