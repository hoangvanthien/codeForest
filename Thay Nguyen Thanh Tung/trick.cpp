// RM
#include "bits/stdc++.h"

using namespace std;

const int N = 200005;
const int oo = 1000000007;
long long a, b, c, d, bs = 1000000000;

void multi(long long x, long long y, long long ta[5]) {
    long long aa[5], bb[5], t[5];
    memset(aa, 0, sizeof aa);
    memset(bb, 0, sizeof bb);
    memset(t, 0, sizeof t);
    aa[0] = x % bs, aa[1] = x / bs;
    bb[0] = y % bs, bb[1] = y / bs;
    // aa x bb
    for (int i = 0; i < 5; ++i) t[i] = 0, ta[i] = 0;
    long long nh = 0, tg;
    for (int i = 0; i < 5; ++i) {
        tg = aa[i] * bb[0] + nh;
        ta[i] = tg % bs;
        nh = tg / bs;
    }
    t[0] = 0;
    for (int i = 0; i < 4; ++i) {
        tg = aa[i] * bb[1] + nh;
        t[i + 1] = tg % bs;
        nh = tg / bs;
    }
    for (int i = 0; i < 5; ++i) {
        tg = t[i] + ta[i] + nh;
        ta[i] = tg % bs;
        nh = tg / bs;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long long sab[5], scd[5];
    multi(a, b, sab);
    multi(c, d, scd);
    for (int i = 0; i < 5; ++i)
        if (sab[i] != scd[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES" << '\n';
    long long ans = 0, k = 0;
    while (true) {
        if (a < b) swap(a, b);
        if (c > d) swap(c, d);
        long long l = 0, r = 0;
        if (b && c) l = 0, r = min(d / b + 7, a / c + 7);
        bool good = 0;
        while (l < r - 1) {
            long long m = (l + r) / 2;
            bool fa = (a - (m - 1) * c > c);
            bool fd = (d - (m - 1) * b > b);
            if (fa && fd) good = 1, l = m;
            else r = m;
        }
        if (good) a -= l * c, d -= l * b, ans += l;
        if (a == b && a == c && a == d) {
            cout << ans + 1 << '\n';
            break;
        }
        if (k != ans) k = ans; else a -= c, d -= b, ++ans;
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}