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

const int N = 200005;
const int oo = 1000000007;
int n;
set<II > s;
vector<II > res;

int gcd(int x, int y) {
    while (y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void add(int numerator, int denominator) {
    if (denominator == 0) return;
    int G = gcd(abs(numerator), abs(denominator));
    numerator /= G;
    denominator /= G;
    if (denominator < 0) denominator *= -1, numerator *= -1;
    if (s.find(mp(numerator, denominator)) == s.end()) {
        s.insert(mp(numerator, denominator));
        res.pb(mp(numerator, denominator));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    II dir = mp(0, 1);
    int x = 0, y = 0;
    while (~sci(n)) {

        while (n + 1 > res.size()) {
            if (x <= 0 && y <= 0 && x == y) dir = mp(0, 1); // up
            else if (x + y == 1 && y > 0) dir = mp(1, 0); // right
            else if (x > 0 && y > 0 && x == y) dir = mp(0, -1); // down
            else if (x > 0 && x + y == 0) dir = mp(-1, 0); // left
            x += dir.F;
            y += dir.S;
            add(y, x);
        }

        if (n + 1 <= res.size()) {
            printf("%d / %d\n", res[n].F, res[n].S);
            continue;
        }

    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}