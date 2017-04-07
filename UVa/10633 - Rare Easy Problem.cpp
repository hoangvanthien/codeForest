// RM
#include "bits/stdc++.h"

using namespace std;

#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define LL long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    LL n;
    while (~scanf("%lld", &n)) {
        if (n == 0) break;
        bool written = false;
        DFOR(i, 9, 0) if ((n - i) % 9 == 0) {
                if (written) printf(" ");
                printf("%lld%d", (n - i) / 9, i);
                written = true;
            }
        puts("");
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}