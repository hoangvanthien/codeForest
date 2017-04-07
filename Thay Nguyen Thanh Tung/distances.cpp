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
int n, d[N][N], x[N], a[N], b[N];
II p[N];

bool solve(int u, int v) {
    f1(k, n) if (d[u][k] == 0) {
            f1(i, n) p[i] = mp(d[i][k], i);
            break;
        }
    sort(p + 1, p + 1 + n);
    f1(i, n) a[i] = p[i].S, x[i] = p[i].F;
    f1(j, n) p[j] = mp(d[u][j], j);
    sort(p + 1, p + 1 + n);
    f1(i, n) b[p[i].S] = i;
    f1(i, n) f1(j, n) {
            int temp = abs(x[a[i]] - x[b[j]]);
            if (temp != d[i][j]) return false;
        }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    f1(i, n) f1(j, n) sci(d[i][j]);
    int Max = 0;
    f1(i, n) f1(j, n) maximize(Max, d[i][j]);
    f1(i, n) f1(j, n) if (Max == d[i][j]) {
                if (!solve(i, j)) {
                    puts("NO");
                    return 0;
                }
                break;
            }
    puts("YES");
    f1(i, n) printf("%d ", x[i]);
    nl;
    f1(i, n) printf("%d ", a[i]);
    nl;
    f1(j, n) printf("%d ", b[j]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}