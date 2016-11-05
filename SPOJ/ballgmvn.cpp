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

const int N = 200005;
const int oo = 1000000007;
int n;
vector<II > a, b;

struct Line {
    double a, b, c;
    int ind = 0;

    Line(double _a, double _b, double _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    bool operator==(const Line &other) const { return mp(mp(a, b), c) == mp(mp(other.a, other.b), other.c); }

    bool operator<(const Line &other) const { return mp(mp(a, b), c) < mp(mp(other.a, other.b), other.c); }

    bool operator>=(const Line &other) const { return mp(mp(a, b), c) >= mp(mp(other.a, other.b), other.c); }
};

Line getLine(II A, II B) {
    if (A.F == B.F) {
        return Line(1, 0, -A.F);
    } else {
        double _a = -(double) (B.S - A.S) / (B.F - A.F);
        double _b = 1.0;
        double _c = -(_a * A.F + _b * A.S);
        return Line(_a, _b, _c);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    f0(i, n) {
        int x, y;
        scii(x, y);
        a.pb(mp(x, y));
    }
    f0(i, n) {
        int x, y;
        scii(x, y);
        b.pb(mp(x, y));
    }
    vector<Line> l1;
    FOR(i, 0, n - 2) {
        l1.clear();
        FOR(j, i + 1, n - 1) {
            l1.pb(getLine(a[i], a[j]));
            l1.back().ind = j;
        }
        sort(l1.begin(), l1.end());
        FOR(j, 0, n - 1) {
            Line l = getLine(a[i], b[j]);
            int pos = lower_bound(l1.begin(), l1.end(), l) - l1.begin();
            if (pos < l1.size() && l1[pos] == l) {
                printf("%d %d %d\n", i + 1, l1[pos].ind + 1, j + n + 1);
                return 0;
            }
        }
    }
    FOR(i, 0, n - 2) {
        l1.clear();
        FOR(j, i + 1, n - 1) {
            l1.pb(getLine(b[i], b[j]));
            l1.back().ind = j;
        }
        sort(l1.begin(), l1.end());
        FOR(j, 0, n - 1) {
            Line l = getLine(b[i], a[j]);
            int pos = lower_bound(l1.begin(), l1.end(), l) - l1.begin();
            if (pos < l1.size() && l1[pos] == l) {
                printf("%d %d %d\n", i + n + 1, l1[pos].ind + n + 1, j + 1);
                return 0;
            }
        }
    }
    puts("-1");

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}