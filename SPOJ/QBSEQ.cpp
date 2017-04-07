#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define maximize(x, y) x=max(x,(y))
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define scii(a, b) scanf("%d%d", &a, &b)

const int N = 1005;
const int oo = 1000000007;
int n, k, a[N], f[N][50];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, k);
    sca(a, n);
    f[0][0] = 1;
    int x = 0;
    f1(i, n + 1) {
        f0(j, i) {
            f0(t, k) if (f[j][t]) maximize(f[i][(t + a[i]) % k], f[j][t] + 1);
        }
    }
    printf("%d\n", f[n + 1][0] - 2);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}