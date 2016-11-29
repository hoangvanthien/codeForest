// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scni(i) int i; scanf("%d",&i)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)
#define scniiii(a, b, c, d) int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1

const int N = 300005;
const int oo = 1000000007;

int n, b[N];
II bit[N], a[N];
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

bool cmp(const II &x, const II &y) {
    return mp(x.F, -x.S) < mp(y.F, -y.S);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    f1(i, n) scii(a[i].F, a[i].S);
    sort(a + 1, a + 1 + n, cmp);
    f1(i, n) b[i] = a[i].S;
    sort(b + 1, b + 1 + n);
    for (int i = 1, cnt = 0; i <= n; ++i) if (!enc[b[i]]) enc[b[i]] = ++cnt;
    f1(i, n) a[i].S = enc[a[i].S];
    int ans = 0;
    f1(i, n) {
        II temp = getVal(a[i].S - 1);
        int len = temp.F + 1;
        ans = temp.S;
        if (ans == 0) ++ans;
        update(a[i].S, len % oo, ans % oo);
    }
    II tmp = getVal((int) enc.size());
    ans = tmp.S;
    int len = tmp.F;
    cout << len << '\n' << ans + (ans == 0);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}