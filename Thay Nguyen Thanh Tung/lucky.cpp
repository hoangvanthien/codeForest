// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define LL long long
#define nl puts("")

LL solve(LL n, LL a, LL b, LL c, LL d) {
    return max(min(b, n) - max(0LL, n - d) + 1, 0LL);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    LL n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << solve(n - a - c, 0LL, b - a, 0LL, d - c);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}