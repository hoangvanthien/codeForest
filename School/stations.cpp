// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1
#ifdef ONLINE_JUDGE
#define printLL(x) printf("%I64d", x)
#else
#define printLL(x) cout << x
#endif

const int N = 205;
const int oo = 1000000007;
int n, k, A, B, a[N], f[N][N];

int dp(int i, int j) {
    if (f[i][j]) return f[i][j];
    if (n - j + 1 < A) return oo;
    if (i == k) {
        if (n - j + 1 > B) return oo;
        f[i][j] = a[n] - a[j];
        return f[i][j];
    }
    int res = oo;
    FOR(t, A, B) {
        minimize(res, max(a[j + t - 1] - a[j], dp(i + 1, j + t)));
    }
    f[i][j] = res;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("stations.inp", "r", stdin);
    freopen("stations.out", "w", stdout);
#endif // ONLINE_JUDGE
    sciiii(n, k, A, B);
    sca(a, n);
    printf("%d", dp(1, 1));
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}