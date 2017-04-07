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

const int N = 1005;
const int oo = 1000000007;
int n, g, a[N];
LL f[N], f2[N];
double ans[N][N];

double heavy(int i, int j) {
    double mean = (double) (f[j] - f[i - 1]) / (j - i + 1);
//    double res = 0;
//    FOR(k, i, j) res += ((double) a[k] - mean) * ((double) a[k] - mean);
//    return res;
    return (double) f2[j] - f2[i - 1] - mean * (f[j] - f[i - 1]);
}

double dp(int i, int j) {
    if (ans[i][j] > 0) return ans[i][j];
    if (j == 1) return ans[i][j] = heavy(i, n);
    double res = (double) 1e30;
    FOR(k, i, n - j + 1) minimize(res, heavy(i, k) + dp(k + 1, j - 1));
//    if (res - 0 < 1e-9) {
//        puts("0.00");
//        exit(0);
//    }
    return ans[i][j] = res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("lss.inp", "r", stdin);
   freopen("lss.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, g);

    sca(a, n);
//    srand(time(NULL));
//    n = 20, g = 4;
//    f1(i, n) a[i] = rand() % 1000000 + 1;
    f1(i, n) f[i] = f[i - 1] + a[i], f2[i] = f2[i - 1] + (LL) a[i] * a[i];
    printf("%.2lf", dp(1, g));
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}