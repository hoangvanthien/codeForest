// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

int n, m, k;

bool check(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        int digit = x % 10;
        if (digit == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~sciii(n, m, k)) {
        if (n == 0 && m == 0 && k == 0) break;
        int ppl = 0, cnt = 0, last = 0, dir = 1;
        FOR(i, 1, 1000000) {
            if (last == n) dir = -1;
            if (last == 1) dir = 1;
            ppl = ppl + dir;
            if (ppl == m && check(i)) ++cnt;
            if (cnt == k) {
                printf("%d\n", i);
                break;
            }
            last = ppl;
        }
    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}