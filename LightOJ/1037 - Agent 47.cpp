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

const int N = 16;
const int oo = 1000000007;
int hp[N], n, f[1 << N];
vector<int> v[N];
char T[N];
int c[N][N];

int getMaxWeapon(int state, int target) {
    int res = 1;
    f0(gun, n)
        if (state & (1 << gun)) maximize(res, c[gun + 1][target]);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    f0(i, 1 << 15) v[__builtin_popcount(i)].pb(i);
    scni(TT);
    f1(__, TT) {
        sci(n);
        f0(i, 1 << n) f[i] = oo;
        f[0] = 0;
        sca(hp, n);
        f1(i, n) {
            scanf("%s", T);
            f0(j, n) c[i][j + 1] = T[j] - '0';
        }
        f0(i, n) {
            forit(it, v[i]) {
                int state = *it;
                if (state > (1 << n)) break;
                f0(j, n) if (!(state & (1 << j))) {
                        minimize(f[state | (1 << j)], f[state] + (hp[j + 1] - 1) / getMaxWeapon(state, j + 1) + 1);
                    }
            }
        }
        printf("Case %d: %d\n", __, f[(1 << n) - 1]);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}