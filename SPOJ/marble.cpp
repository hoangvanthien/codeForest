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

const int N = 50005;
const int oo = 1000000007;
int n, k, q;
II ro[N], co[N];

struct vertex {
    int mn, mx, lazymin, lazymax;
} hor[N * 4], ver[N * 4];

void init(int node, int l, int r, vertex *T, II *ar) {
    if (l > r) return;
    if (l == r) {
        T[node].mn = ar[l].F;
        T[node].mx = ar[l].S;
        T[node].lazymax = 0;
        T[node].lazymin = oo;
        return;
    }
    int mid = (l + r) / 2;
    init(lc, l, mid, T, ar);
    init(rc, mid + 1, r, T, ar);
    T[node].mn = min(T[lc].mn, T[rc].mn);
    T[node].mx = max(T[lc].mx, T[rc].mx);
    T[node].lazymax = 0;
    T[node].lazymin = oo;
}

void lazyUpd_min(int node, int l, int r, int val, vertex *T) {
    if (T[node].lazymin > val) {
        minimize(T[node].lazymin, val);
        minimize(T[node].mn, val);
    }
}

void lazyUpd_max(int node, int l, int r, int val, vertex *T) {
    if (T[node].lazymax < val) {
        maximize(T[node].lazymax, val);
        maximize(T[node].mx, val);
    }
}

void update_min(int node, int l, int r, int i, int j, int val, vertex *T) {
    if (l > r || i > r || j < l) return;
    if (i <= l && r <= j) {
        lazyUpd_min(node, l, r, val, T);
        return;
    }
    int mid = (l + r) / 2;
    if (T[node].lazymin != oo) {
        int &v = T[node].lazymin;
        lazyUpd_min(lc, l, mid, v, T);
        lazyUpd_min(rc, mid + 1, r, v, T);
        v = oo;
    }
    update_min(lc, l, mid, i, j, val, T);
    update_min(rc, mid + 1, r, i, j, val, T);
    T[node].mn = min(T[lc].mn, T[rc].mn);
}

void update_max(int node, int l, int r, int i, int j, int val, vertex *T) {
    if (l > r || i > r || j < l) return;
    if (i <= l && r <= j) {
        lazyUpd_max(node, l, r, val, T);
        return;
    }
    int mid = (l + r) / 2;
    if (T[node].lazymax != 0) {
        int &v = T[node].lazymax;
        lazyUpd_max(lc, l, mid, v, T);
        lazyUpd_max(rc, mid + 1, r, v, T);
        v = 0;
    }
    update_max(lc, l, mid, i, j, val, T);
    update_max(rc, mid + 1, r, i, j, val, T);
    T[node].mx = max(T[lc].mx, T[rc].mx);
}

int query_min(int node, int l, int r, int ind, vertex *T) {
    if (ind < l || ind > r || l > r) return oo;
    if (l == r && l == ind) return T[node].mn;
    int mid = (l + r) / 2;
    if (T[node].lazymin != oo) {
        int &v = T[node].lazymin;
        lazyUpd_min(lc, l, mid, v, T);
        lazyUpd_min(rc, mid + 1, r, v, T);
        v = oo;
    }
    return min(query_min(lc, l, mid, ind, T), query_min(rc, mid + 1, r, ind, T));
}

int query_max(int node, int l, int r, int ind, vertex *T) {
    if (ind < l || ind > r || l > r) return 0;
    if (l == r && l == ind) return T[node].mx;
    int mid = (l + r) / 2;
    if (T[node].lazymax != 0) {
        int &v = T[node].lazymax;
        lazyUpd_max(lc, l, mid, v, T);
        lazyUpd_max(rc, mid + 1, r, v, T);
        v = 0;
    }
    return max(query_max(lc, l, mid, ind, T), query_max(rc, mid + 1, r, ind, T));
}

LL f[N];
string direc = "LRTB";

//LL cal(LL x, LL cnt) {
//    return f[x] - f[max(x - cnt, 0)];
//}
bool ar[1005][1005];

LL process(char ch, int z, int x, int y) {
    LL ans = 0;
    if (ch == 'L') {
        y = 1;
        while (ar[x][y] == 0 && y <= n) ++y;
        if (y != n + 1) {
            DFOR(i, y - 1, max(y - z, 1)) ar[x][i] = 1, ans += i;
        } else {
            ans = (LL) n * z;
        }
    }
    if (ch == 'R') {
        y = n;
        while (ar[x][y] == 0 && y >= 1) --y;
        if (y != 0) {
            FOR(i, y + 1, min(y + z, n)) ar[x][i] = 1, ans += n - i + 1;
        } else {
            ans = (LL) n * z;
        }
    }
    if (ch == 'T') {
        x = 1;
        while (ar[x][y] == 0 && x <= n) ++x;
        if (x != n + 1) {
            DFOR(i, x - 1, max(x - z, 1)) ar[i][y] = 1, ans += i;
        } else {
            ans = (LL) n * z;
        }
    }
    if (ch == 'B') {
        x = n;
        while (ar[x][y] == 0 && x >= 1) --x;
        if (x != 0) {
            FOR(i, x + 1, min(x + z, n)) ar[i][y] = 1, ans += n - i + 1;
        } else {
            ans = (LL) n * z;
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

//    sci(n);
//    f1(i, n) {
//        scanf("%d", &ro[i].F);
//    }
//    init(1, 1, n, row, ro);
//    sci(q);
//    f1(i, q) {
//        int x, y, z;
//        sci(x);
//        if (x == 0) {
//            sciii(x, y, z);
//            update_min(1, 1, n, x, y, z, row);
//        } else {
//            sci(x);
//            printf("%d\n", query_min(1, 1, n, x, row));
//        }
//    }
    srand(time(NULL));
    sciii(n, k, q);
    f1(i, n) f[i] = f[i - 1] + i;
    f1(i, n) {
        if (ro[i].F == 0) ro[i].F = oo;
        if (co[i].F == 0) co[i].F = oo;
    }
    f1(i, k) {
        int x, y;
        scii(x, y);
        minimize(ro[x].F, y);
        maximize(ro[x].S, y);
        minimize(co[y].F, x);
        maximize(co[y].S, x);
        if (n <= 1000) ar[x][y] = true;
    }
    init(1, 1, n, ver, ro);
    init(1, 1, n, hor, co);
    scanf("\n");
    f1(_t, q) {
        char ch;
        int x, y, z, temp;
        LL ans;
        scanf("%c", &ch);
        sciii(z, x, y);
        scanf("\n");

//        if (n <= 1000) {
//            printf("%lld\n", process(ch, z, x, y));
//            continue;
//        }
//        ch = direc[rand() % 4];
//        x = rand() % n + 1;
//        y = rand() % n + 1;
//        z = rand() % (n * 2);
//        LL ans2 = process(ch, z, x, y);
//        printf("%c %d %d %d %lld ", ch, z, x, y, ans2);
        if (ch == 'L') {
            y = query_min(1, 1, n, x, ver);
            if (y != oo) {
                update_min(1, 1, n, max(y - z, 1), y - 1, x, hor);
                update_max(1, 1, n, max(y - z, 1), y - 1, x, hor);
                update_min(1, 1, n, x, x, max(y - z, 1), ver);
                ans = f[y - 1] - f[max(y - z, 1) - 1];
            } else {
                ans = (LL) n * z;
            }
        }
        if (ch == 'R') {
            y = query_max(1, 1, n, x, ver);
            if (y != 0) {
                update_min(1, 1, n, y + 1, min(y + z, n), x, hor);
                update_max(1, 1, n, y + 1, min(y + z, n), x, hor);
                update_max(1, 1, n, x, x, min(y + z, n), ver);
                ans = f[n - y] - f[n - min(y + z, n)];
            } else {
                ans = (LL) n * z;
            }
        }
        if (ch == 'T') {
            x = query_min(1, 1, n, y, hor);
            if (x != oo) {
                update_min(1, 1, n, max(x - z, 1), x - 1, y, ver);
                update_max(1, 1, n, max(x - z, 1), x - 1, y, ver);
                update_min(1, 1, n, y, y, max(x - z, 1), hor);
                ans = f[x - 1] - f[max(x - z, 1) - 1];
            } else {
                ans = (LL) n * z;
            }
        }
        if (ch == 'B') {
            x = query_max(1, 1, n, y, hor);
            if (x != 0) {
                update_min(1, 1, n, x + 1, min(x + z, n), y, ver);
                update_max(1, 1, n, x + 1, min(x + z, n), y, ver);
                update_max(1, 1, n, y, y, min(x + z, n), hor);
                ans = f[n - x] - f[n - min(x + z, n)];
            } else {
                ans = (LL) n * z;
            }
        }
        printf("%lld\n", ans);
//        if (ans2 != ans) break;
//        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}