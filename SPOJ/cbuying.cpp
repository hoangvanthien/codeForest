// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define F first
#define S second
#define II pair<long long, long long>
#define LL long long
#define nl puts("")
#define scii(a, b) scanf("%lld %lld", &a, &b)

const int N = 200005;
const int oo = 1000000007;
LL n, money;
II a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, money);
    f1(i, n) scii(a[i].F, a[i].S);
    sort(a + 1, a + 1 + n);
    LL ans = 0;
    f1(i, n) {
        LL sl = min(money / a[i].F, a[i].S);
        ans += sl;
        money -= sl * a[i].F;
    }
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}