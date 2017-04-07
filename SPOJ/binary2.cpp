// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
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

const int N = 1000005;
const int oo = 1000000000;
int n, m;
LL f[N][2], sf[N][2];

inline LL getSum(int i, int j, int t) {
    if (i > j) swap(i, j);
    LL res = 0;
    if (i - 1 >= 0) res = sf[j][t] - sf[i - 1][t]; else res = sf[j][t];
    while (res < 0) res += oo;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~scii(n, m)) {
        memset(f, 0, sizeof f);
        memset(sf, 0, sizeof sf);
        f[0][0] = f[0][1] = f[1][0] = f[1][1] = 1;
        sf[0][0] = sf[0][1] = 1;
        sf[1][0] = sf[1][1] = 2;
        FOR(i, 2, n) {
            f[i][0] = (f[i][0] + f[i - 1][1] + getSum(i - min(i - 1, m - 1) - 1, i - 2, 0)) % oo;
            sf[i][0] = (sf[i - 1][0] + f[i][0]) % oo;
            f[i][1] = (f[i][1] + f[i - 1][0] + getSum(i - min(i - 1, m - 1) - 1, i - 2, 1)) % oo;
            sf[i][1] = (sf[i - 1][1] + f[i][1]) % oo;
        }
        LL ans = (f[n][0] + f[n][1]) % oo;
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}