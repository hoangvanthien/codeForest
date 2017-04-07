#include "bits/stdc++.h"

using namespace std;

const int N = 35;
const int oo = 1000000007;
int n, m, k, f[N][N], a[N];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d %d %d", &n, &m, &k);
    f[0][0] = f[1][0] = 1;
    for (int j = 1; j < n; ++j) {
        for (int x = 0; x <= k; ++x) f[0][j] += f[x][j - 1];
        for (int i = 1; i <= j + 1; ++i) {
            f[i][j] = f[i - 1][j - 1];
        }
    }
    --m;
    int c = 0;
    for (int j = n - 1; j >= 0; --j) {
        int cnt = 0;
        for (int i = 1; i <= k - c; ++i) cnt += f[i][j];
        if (cnt <= m) {
            m -= cnt;
            a[j] = 1;
            c = 0;
        } else a[j] = 0, ++c;
    }
    int m = 0;
    for (int j = 0; j < n; ++j) m |= ((1 << j) * a[j]);
    memset(a, 0, sizeof a);
    for (int j = n - 1; j >= 0; --j) a[j] = m % 10, m /= 10;
    for (int j = 0; j < n; ++j) printf("%d ", a[j]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}