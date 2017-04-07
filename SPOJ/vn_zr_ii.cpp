#include "bits/stdc++.h"

using namespace std;

const int N = 35;

// f[i] = number of red 0s of x that has exactly i bits and no leading zero
long long f[N];
long long a[N], s[N];

long long len(long long x) {
    if (x == 0) return 1;
    long long res = 0;
    while (x) { ++res, x >>= 1; }
    return res;
}

long long brute(long long n, long long k) {
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        long long cnt = 0, l = len(i);
        for (long long j = 0; j < l; ++j)
            if (i & (1 << j)) {
                if (cnt > 0) {
                    res += (cnt > 0) ? (cnt - 1) / k + 1 : 0;
                    cnt = 0;
                }
            }
            else ++cnt;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    long long n, k;
    while (~scanf("%lld %lld", &n, &k)) {
//        printf("Answer = %lld\n", brute(n, k));
        memset(f, 0, sizeof f);
        memset(a, 0, sizeof a);
        memset(s, 0, sizeof s);
        for (int i = 2; i < 32; ++i) {
            // Add digit 1 after all x that has i-1 bits
            f[i] = f[i - 1];
            for (int t = 1; t <= i - 1; ++t) {
                // Assume x's last t bits are all zeros
                if (t < i - 1)
                    f[i] += (1LL << (i - 2 - t)) * ((t - 1) / k + 1);
                else f[i] += (t - 1) / k + 1;
                f[i] += f[i - 1 - t];
            }
        }
        int l = len(n);
        long long ans = 0;
        for (int i = 1; i < l; ++i) ans += f[i];
        for (int i = l - 1; i >= 0; --i) {
            a[i] = a[i + 1] + 1;
            if (n & (1LL << i)) a[i] = 0;
        }
        for (int i = l - 1; i >= 0; --i) s[i] = s[i + 1] + (a[i] > 0 && (a[i] - 1) % k == 0);
        for (int i = 0; i < l - 1; ++i)
            if (n & (1LL << i)) {
                for (int t = 0; t <= i; ++t) {
                    long long tmp;
                    for (int j = i + 1; j < l; ++j)
                        if (n & (1LL << j)) {
                            tmp = s[j];
                            break;
                        }
                    if (n & (1LL << (i + 1)))
                        tmp += t / k + 1;
                    else {
                        tmp += (a[i + 1] + t) / k + 1;
                    }
                    if (i - t - 1 >= 0)
                        ans += tmp * (1LL << (i - t - 1));
                    else ans += tmp;
                    ans += f[i - t];
                }
            }
        ans += s[0];
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}