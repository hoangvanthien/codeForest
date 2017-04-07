// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define scii(a, b) scanf("%d%d", &a, &b)

int cnt[10];

bool check(int x) {
    memset(cnt, 0, sizeof cnt);
    while (x) {
        if (cnt[x % 10]) return false;
        ++cnt[x % 10];
        x /= 10;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int m, n;
    while (~scii(n, m)) {
        int ans = 0;
        FOR(i, n, m) ans += check(i);
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}