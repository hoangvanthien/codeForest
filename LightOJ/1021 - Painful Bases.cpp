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
int n, k, a[N];
LL f[1 << 17][N];
char T[N];
vector<int> v[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    f0(i, 1 << 16) v[__builtin_popcount(i)].pb(i);
    scni(TT);
    f1(__, TT) {
        scnii(n, k);
        scanf("%s", T);
        int len = (int) strlen(T);
        f0(i, len)
            if (T[i] >= 'A') a[i] = T[i] - 'A' + 10;
            else a[i] = T[i] - '0';
        reverse(a, a + len);
        memset(f, 0, sizeof f);
        f[0][0]++;
        f0(i, len) {
            forit(it, v[i]) {
                int state = *it;
                f0(r, k) {
                    f0(j, len)
                        if (!(state & (1 << j))) {
                            f[state | (1 << j)][(r * n + a[j]) % k] += f[state][r];
                        }
                }
            }
        }
        printf("Case %d: %lld\n", __, f[(1 << len) - 1][0]);

    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}