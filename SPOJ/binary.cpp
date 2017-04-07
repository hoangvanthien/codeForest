#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define LL long long
#define nl puts("")
#define scii(a, b) scanf("%d%d", &a, &b)

const int N = 35;
LL c[N][N];

LL nCr(int n, int r) {
    if (n < r || r < 0 || n < 0) return 0;
    if (c[n][r]) return c[n][r];
    if (r == 0 || r == n) return 1;
    return c[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int n, k, a[N];

int len(int x) {
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
    while (~scii(n, k)) {
        memset(a, 0, sizeof a);
        int l = len(n);
        DFOR(i, l - 1, 0) {
            a[i] = a[i + 1] + 1;
            if (n & (1 << i)) --a[i];
        }
        LL ans = 0;
        FOR(i, k, l - 2) ans += nCr(i, k);
        FOR(i, 0, l - 2) if (n & (1 << i)) {
                ans += nCr(i, k - a[i] - 1);
            }
        if (a[0] == k) ++ans;
        if (k == 1) ans += (n != 0);
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}