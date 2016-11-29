// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)

const int N = 100005;
const int oo = 1000000007;

int n, a[N], b[N];
II bit[N];
map<int, int> enc;

void update(int i, int len, int cnt) {
    while (i <= n) {
        if (bit[i].F < len) bit[i] = mp(len, cnt);
        else if (bit[i].F == len) bit[i].S = (bit[i].S + cnt) % oo;
        i += i & (-i);
    }
}

II getVal(int i) {
    II res = mp(0, 0);
    while (i > 0) {
        if (bit[i].F > res.F) res = bit[i];
        else if (bit[i].F == res.F) res.S = (res.S + bit[i].S) % oo;
        i -= i & (-i);
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    f1(i, n) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1, cnt = 0; i <= n; ++i) if (!enc[b[i]]) enc[b[i]] = ++cnt;
    f1(i, n) a[i] = enc[a[i]];
    int ans = 0;
    f1(i, n) {
        II temp = getVal(a[i] - 1);
        int len = temp.F + 1;
        ans = temp.S;
        if (ans == 0) ++ans;
        update(a[i], len % oo, ans % oo);
    }
    ans = getVal((int) enc.size()).S;
    cout << ans + (ans == 0);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}