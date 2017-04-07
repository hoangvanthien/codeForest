#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)

const int N = 60005;
const int oo = 1000000007;
int n, a[N], b[N], f[N];

int dp(int i) {
    if (i > n) return 0;
    if (i == n) return a[i];
    if (f[i]) return f[i];
    return f[i] = min(a[i] + dp(i + 1), b[i] + dp(i + 2));
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    sca(b, n - 1);
    cout << dp(1);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}