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

const int N = 25;
const int oo = 1000000007;
int d[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int x, n = 20, test = 0;
    while (~sci(x)) {
        f1(i, n) f1(j, n) d[i][j] = (i != j) ? oo : 0;
        f1(_, x) {
            scni(y);
            d[1][y] = d[y][1] = 1;
        }
        FOR(i, 2, 19) {
            sci(x);
            f1(__, x) {
                scni(y);
                d[i][y] = d[y][i] = 1;
            }
        }
        f1(k, n) f1(i, n) f1(j, n) minimize(d[i][j], d[i][k] + d[k][j]);
        scni(cntQuery);
        printf("Test Set #%d\n", ++test);
        while (cntQuery--) {
            scnii(u, v);
            printf("%2d to %2d:%2d\n", u, v, d[u][v]);
        }
        nl;
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}