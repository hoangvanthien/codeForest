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

const int N = 65;
const int oo = 1000000007;
int n, a[N], k, lim[2];
LL f[2][N][N];
bool mark[2][N][N];
char T[N];

LL dp(int t, int i, int x) {
    if (x < 0 || x > lim[t]) return 0;
    if (mark[t][i][x]) return f[t][i][x];
    if (i == n) return x == 0;
    LL res = 0;
    if (x + 1 <= lim[t]) res += dp(t, i + 1, x + 1);
    if (x - 1 >= 0) res += dp(t, i + 1, x - 1);
    mark[t][i][x] = true;
    return f[t][i][x] = res;
}

inline LL cal(int t, char ch, int i) {
    if (ch == '(') return dp(t, i - 1, a[i - 1]) - dp(t, i, a[i - 1] - 1);
    return dp(t, i - 1, a[i + 1]) - dp(t, i, a[i + 1] + 1);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, k);
    scanf("%s", T);
    f0(i, n) a[i + 1] = a[i] + (T[i] == '(' ? 1 : -1);
    lim[0] = k, lim[1] = k - 1;
    dp(0, 0, 0);
    dp(1, 0, 0);
    printf("%lld\n", f[0][0][0] - f[1][0][0]);
    LL ans = 0;
    f0(i, n) if (T[i] == ')') {
            LL res = cal(0, '(', i + 1);
            ans += res;
        }
    f0(i, n) if (T[i] == ')') {
            if (a[i + 1] == k - 1) break;
            LL res = cal(1, '(', i + 1);
            ans -= res;
        }
    printf("%lld\n", ans + 1);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}