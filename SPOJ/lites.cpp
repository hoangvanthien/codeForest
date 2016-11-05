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

const int N = 100005;
const int oo = 1000000007;
int n, q, a[N];

struct vertex {
    int sum, lazy;
} T[N * 4];

void initTree(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
        T[node].sum = a[l];
        T[node].lazy = -1;
        return;
    }
    int mid = (l + r) / 2;
    initTree(lc, l, mid);
    initTree(rc, mid + 1, r);
    T[node].sum = T[lc].sum + T[rc].sum;
    T[node].lazy = -1;
}

void lazyUpd(int node, int l, int r) {
    if (T[node].lazy) {
        T[lc].lazy = 1 - T[lc].lazy;
        T[rc].lazy = 1 - T[rc].lazy;
        T[node].lazy = 1 - T[node].lazy;
        int mid = (l + r) / 2;
        T[lc].sum = mid - l + 1 - T[lc].sum;
        T[rc].sum = r - mid - T[rc].sum;
    }
}

void update(int node, int l, int r, int i, int j) {
    if (l > r) return;
    if (i > r || j < l) return;
    if (i <= l && r <= j) {
        T[node].sum = r - l + 1 - T[node].sum;
        T[node].lazy = 1 - T[node].lazy;
        return;
    }
    lazyUpd(node, l, r);
    int mid = (l + r) / 2;
    update(lc, l, mid, i, j);
    update(rc, mid + 1, r, i, j);
    T[node].sum = T[lc].sum + T[rc].sum;
}

int getSum(int node, int l, int r, int i, int j) {
    if (i <= l && r <= j) return T[node].sum;
    if (l > r) return 0;
    if (i > r || j < l) return 0;
    lazyUpd(node, l, r);
    int mid = (l + r) / 2;
    return getSum(lc, l, mid, i, j) + getSum(rc, mid + 1, r, i, j);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("lites.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, q);
//    initTree(1, 1, n);
    f1(i, q) {
        int type, x, y;
        sciii(type, x, y);
        if (type == 0) update(1, 1, n, x, y);
        else printf("%d\n", getSum(1, 1, n, x, y));
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}