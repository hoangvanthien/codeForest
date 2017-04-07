#include "bits/stdc++.h"

using namespace std;

const int N = 35;
const int oo = 1000000007;
int l, r, k, b, f[N][N], ex[N];

int len(int x) {
    if (x == 0) return 1;
    int res = 0;
    while (x) {
        x >>= 1;
        ++res;
    }
    return res;
}

int solve(int x) {
    int res = 0;
    if (b == 2) {
        int cnt = 0, n = len(x);
        for (int j = n - 1; j >= 0 && cnt <= k; --j) {
            if (x & (1 << j)) {
                if (j > 0) res += f[k - cnt][j - 1];
                ++cnt;
            }
        }
        if (__builtin_popcount(x) == k) ++res;
        return res;
    }
    int lim = (int) (log(x) / log(b)) + 1;
    for (int i = 0; i < (1 << lim); ++i)
        if (__builtin_popcount(i) == k) {
            long long tmp = 0;
            for (int j = 0; j < lim; ++j)
                if (i & (1 << j)) {
                    tmp += ex[j];
                }
            if (tmp <= x) ++res;
        }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d %d %d %d", &l, &r, &k, &b);
    ex[0] = 1;
    for (int i = 1; i < N; ++i) ex[i] = ex[i - 1] * b;
    f[0][0] = f[1][0] = 1;
    for (int j = 1; j <= 31; ++j) {
        for (int i = 0; i <= j + 1; ++i) {
            f[i][j] = f[i][j - 1];
            if (i > 0) f[i][j] += f[i - 1][j - 1];
        }
    }
    cout << solve(r) - solve(l - 1);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}