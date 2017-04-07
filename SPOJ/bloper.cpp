// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define scii(a, b) scanf("%d%d", &a, &b)

const int N = 200005;
int m, n;
bool mark[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, m);
    int Sum = n * (n + 1) / 2;
    --Sum;
    --m;
    if (Sum < m || Sum < -m || (Sum - m) % 2 == 1) {
        puts("Impossible");
        return 0;
    }
    int x = (Sum - m) / 2;
    x = Sum - x;
    int Max = n;
    while (x > 0) {
        mark[min(x, Max)] = true;
        x -= min(x, Max);
        --Max;
    }
    printf("1");
    FOR(i, 2, n) if (mark[i]) printf("+%d", i); else printf("-%d", i);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
} 