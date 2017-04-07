#include "bits/stdc++.h"

using namespace std;

const int N = 52;
const int oo = 1000000007;
int m, p, c[N], ans[N];
long long power[N], f[40][N], n, q;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    power[0] = 1;

    scanf("%lld %d %d %lld", &n, &m, &p, &q);
    for (int i = 1; i <= (m - 1) / 2; ++i) scanf("%d", &c[i]);
    c[(m - 1) / 2 + 1] = 36;
    // Group Index
    int gi = (p + 1) / 2;
    // Lower Bound and Upper Bound
    int k = c[gi - 1], r = c[gi];
    for (int i = 1; i < 12; ++i) power[i] = power[i - 1] * r;
    for (int j = 0; j < 11; ++j) {
        long long sum = 0;
        if (j > 0)
            for (int i = 0; i < r; ++i) sum += f[i][j - 1];
        for (int i = 0; i < r; ++i) {
            if (i < k) f[i][j] = sum;
            else f[i][j] = power[j];
        }
    }

    if (p % 2 == 0) {
        // How many tax(k,r) string <= n ?
        vector<int> vn;
        ++n;
        while (n) {
            vn.push_back(n % 36);
            n /= 36;
        }
        int l = (int) vn.size();
        long long gs = 0; // Group Size
        bool flag = false;
        for (int j = l - 1; j >= 0; --j) {
            int lim = min(vn[j], r);
            for (int i = 0; i < lim; ++i) {
                if (!flag) gs += f[i][j];
                else gs += power[j];
            }
            if (lim >= k) flag = true;
            if (lim >= r) break;
        }
        if (gi == 1) gs--;
        q = gs - q + 1;
    }
    if (gi != 1) q--;
    bool flag = false;
    for (int j = 10; j >= 0; --j) {
        int i = 0;
        if (!flag) for (; i < r && q >= f[i][j]; ++i) q -= f[i][j];
        else for (; i < r && q >= power[j]; ++i) q -= power[j];
        ans[j] = i;
        if (i >= k) flag = true;
    }
    vector<int> v;
    for (int j = 0; j < N; ++j) v.push_back(ans[j]);
    while (v.size() > 1 && v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        if (v[i] < 10) printf("%d", v[i]); else printf("%c", 'a' + v[i] - 10);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}