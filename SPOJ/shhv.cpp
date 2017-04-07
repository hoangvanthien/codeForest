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

const int N = 15;
const int oo = 1000000007;
int p[N], a[N], n, k, mark[N];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~sci(a[++n]));
    n -= 2;
    p[0] = 1;
    f1(i, n) p[i] = p[i - 1] * i;
    f1(i, n) {
        mark[a[i]] = 1;
        int cnt = 0;
        f1(j, a[i] - 1) if (!mark[j]) ++cnt;
        k += p[n - i] * cnt;
    }
    ++k;
    printf("%d\n", k);
    k = a[n + 1];
    f1(i, n) mark[i] = 0;
    f1(i, n) {
        int cnt = (k - 1) / p[n - i] + 1;
        k -= (cnt - 1) * p[n - i];
        for (int j = 1; j <= n && cnt != 0; ++j)
            if (!mark[j]) {
                --cnt;
                if (cnt == 0) a[i] = j, mark[j] = 1;
            }
    }
    f1(i, n) printf("%d ", a[i]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}