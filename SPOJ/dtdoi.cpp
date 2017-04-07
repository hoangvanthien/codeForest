// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define scii(a, b) scanf("%d%d", &a, &b)

const int N = 200005;
const int oo = 1000000007;
int n, money, a[N], f[N];

int dp(int x) {
    if (x == 0) return 0;
    if (f[x]) return f[x];
    int res = oo;
    FOR(i, 1, n) if (x >= a[i]) minimize(res, 1 + dp(x - a[i]));
    return f[x] = res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, money);
    sca(a, n);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    if (money > a[n]) {
        ans += money / a[n] - 1;
        money %= a[n];
        money += a[n];
    }
    printf("%d", ans + dp(money));

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
} 