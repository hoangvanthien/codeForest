// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define sci(i) scanf("%d",&i)
#define scni(i) int i; scanf("%d",&i)

const int N = 205;
const int oo = 1000000007;
int a[N][N], f[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TTest);
    f1(__test, TTest) {
        scni(n);
        FOR(i, 1, n) FOR(j, 1, i) sci(a[i][j]);
        FOR(i, 1, n - 1) FOR(j, 1, n - i) sci(a[n + i][j]);
        memset(f, 0, sizeof f);
        f[1][1] = a[1][1];
        FOR(i, 2, n) FOR(j, 1, i) f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
        FOR(i, 1, n - 1) FOR(j, 1, n - i) f[n + i][j] = max(f[n + i - 1][j], f[n + i - 1][j + 1]) + a[n + i][j];
        printf("Case %d: %d\n", __test, f[n * 2 - 1][1]);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}