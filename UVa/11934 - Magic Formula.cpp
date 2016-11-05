// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)

const int N = 200005;
const int oo = 1000000007;
int a, b, c, L, d;

int f(int x) {
    return a * x * x + b * x + c;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    while (~scanf("%d%d%d%d%d", &a, &b, &c, &d, &L)) {
        if (a == 0 && b == 0 && c == 0 && L == 0 && d == 0) break;
        int ans = 0;
        FOR(i, 0, L) if (f(i) % d == 0) ++ans;
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}