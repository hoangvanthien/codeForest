// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define F first
#define S second
#define II pair<int,int>
#define maximize(x, y) x=max(x,(y))
#define nl puts("")
#define sci(i) scanf("%d",&i)

const int N = 100005;
const int oo = 1000000007;
int n, f[N], pre[N];
II a[N];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    srand(time(NULL));
    sci(n);
    f1(i, n) sci(a[i].F), a[i].S = i;
    sort(a + 1, a + 1 + n);
    int ans = 1;
    FOR(d, 1, 100) {
        f1(i, n) f[i] = pre[i] = 0;
        int j = 1;
        f1(i, n) {
            while (j <= n && a[j].F + d < a[i].F) ++j;
            while (j + 1 <= n && a[j + 1].F + d == a[i].F && a[j + 1].S < a[i].S) ++j;
            if (j <= n && a[j].F + d == a[i].F && a[j].S < a[i].S) pre[a[i].S] = a[j].S;
        }
        f1(i, n) f[i] = f[pre[i]] + 1;
        f1(i, n) maximize(ans, f[i]);
    }
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}