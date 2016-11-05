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
#define mn first
#define mx second
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
int n, q, a[N];

II T[N * 4];

void initTree(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
        T[node].mn = T[node].mx = a[l];
        return;
    }
    int mid = (l + r) / 2;
    initTree(lc, l, mid);
    initTree(rc, mid + 1, r);
    T[node].mn = min(T[lc].mn, T[rc].mn);
    T[node].mx = max(T[lc].mx, T[rc].mx);
}

II query(int node, int l, int r, int i, int j) {
    if (i <= l && r <= j) return T[node];
    if (l > r) return mp(oo, -1);
    if (i > r || j < l) return mp(oo, -1);
    int mid = (l + r) / 2;
    II p1 = query(lc, l, mid, i, j);
    II p2 = query(rc, mid + 1, r, i, j);
    return mp(min(p1.mn, p2.mn), max(p1.mx, p2.mx));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    scii(n, q);
    sca(a, n);
    initTree(1, 1, n);
    f1(i, q) {
        int x, y;
        scii(x, y);
        II res = query(1, 1, n, x, y);
        printf("%d\n", res.mx - res.mn);
    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}