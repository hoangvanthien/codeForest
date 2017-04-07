/*
You can go the distance
You can run the mile
You can walk straight through hell with a smile

You can be the hero
You can get the gold
Breaking all the records they thought never could be broke

Yeah, do it for your people
Do it for your pride
How are you ever gonna know if you never even try?

Do it for your country
Do it for your name
'Cause there's gonna be a day...

When you're standing in the hall of fame
And the world's gonna know your name
'Cause you burn with the brightest flame

 -- "Hall Of Fame" --

 */

// Code by an idiot.

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

const int N = 65;
const int oo = 1000000007;
int n;
vector<pair<II, int> > a;
vector<II > b;
int check[N][N];
bool selected[N], Xe[N][N], Ma[N][N], Tuong[N][N], Hau[N][N];
LL tt;

inline bool xe(int x, int y, int u, int v) {
    return (x == u) || (y == v);
}

inline bool ma(int x, int y, int u, int v) {
    return (abs(x - u) == 2 && abs(y - v) == 1) || (abs(x - u) == 1 && abs(y - v) == 2);
}

inline bool tuong(int x, int y, int u, int v) {
    return (abs(x - u) == abs(y - v));
}

inline bool hau(int x, int y, int u, int v) {
    return xe(x, y, u, v) || tuong(x, y, u, v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int cnt = 0;
    sci(n);
    LL sum = 0;
    f1(i, n) {
        int x, y, val;
        sciii(x, y, val);
        a.pb(mp(mp(x, y), val));
        check[x][y] = true;
        sum += val;
    }
    f1(i, 8) f1(j, 8) if (!check[i][j]) b.pb(mp(i, j));
    f0(i, a.size())
        f0(j, b.size()) {
            Xe[i][j] = xe(a[i].F.F, a[i].F.S, b[j].F, b[j].S);
            Ma[i][j] = ma(a[i].F.F, a[i].F.S, b[j].F, b[j].S);
            Tuong[i][j] = tuong(a[i].F.F, a[i].F.S, b[j].F, b[j].S);
            Hau[i][j] = hau(a[i].F.F, a[i].F.S, b[j].F, b[j].S);
        }
    int sz = b.size();
    LL ans = 0, res = 0;
    f0(x, sz) f0(m, sz) if (x != m)
                f0(t, sz) if (t != m && t != x)
                        f0(h, sz) if (h != x && t != h && h != m) {
                                res = 0;
                                f0(i, a.size())
                                    if (Xe[i][x] || Ma[i][m] || Tuong[i][t] || Hau[i][h]) res += a[i].S;
                                maximize(ans, res);
                                if (ans == sum) {
                                    cout << ans;
                                    return 0;
                                }
                            }

    cout << ans;

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}