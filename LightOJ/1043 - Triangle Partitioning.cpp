// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define scni(i) int i; scanf("%d",&i)

const int N = 200005;
const int oo = 1000000007;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(T);
    FOR(__test, 1, T) {
        double AB, AC, BC, r;
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);
        printf("Case %d: %.7lf\n", __test, AB * sqrt(r / (r + 1)));
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}