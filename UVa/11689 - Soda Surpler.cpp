// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define scni(i) int i; scanf("%d",&i)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)

const int N = 200005;
const int oo = 1000000007;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(T);
    while (T--) {
        scniii(e, f, c);
        e += f;
        int ans = 0;
        while (e >= c) {
            e = e - c + 1;
            ++ans;
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}