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

const int N = 35;
const int oo = 1000000007;
int n, a[N], mark[N][N];
LL f[N][N], k;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    n = n * 2 + 1;
    sca(a, n);
    f[n][0] = 1;
    mark[n][0] = 1;
    DFOR(i, n - 1, 1) {
        f0(j, N) if (mark[i + 1][j]) {
                if (j - 1 >= 0) mark[i][j - 1] = 1;
                mark[i][j + 1] = 1;
            }
        f0(j, N) if (mark[i][j]) {
                if (j > 0) f[i][j] += f[i + 1][j - 1];
                f[i][j] += f[i + 1][j + 1];
            }
    }

    k = 0;
    f1(i, n) {
        f0(j, N) {
            if (j == a[i]) break;
            if (mark[i][j]) {
                k += f[i][j];
                if (j > 0) mark[i + 1][j - 1] = 0;
                mark[i + 1][j + 1] = 0;
            }
        }
        f0(j, N) mark[i + 1][j] = 0;
        if (a[i] > 0) mark[i + 1][a[i] - 1] = 1;
        mark[i + 1][a[i] + 1] = 1;
    }
    printf("%lld\n", k + 1);
    scanf("%lld\n", &k);
    --k;
    memset(mark, 0, sizeof mark);
    mark[1][0] = 1;
    f1(i, n) {
        f0(j, N) {
            if (mark[i][j]) {
                if (k >= f[i][j]) k -= f[i][j];
                else {
                    a[i] = j;
                    break;
                }
            }
        }
        if (a[i] > 0) mark[i + 1][a[i] - 1] = 1;
        mark[i + 1][a[i] + 1] = 1;
    }
    f1(i, n) printf("%d ", a[i]);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}