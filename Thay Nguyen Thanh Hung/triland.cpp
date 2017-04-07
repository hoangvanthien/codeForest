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
vector<II > p, cv;
II pivot;

inline LL area(const II &p1, const II &p2, const II &p3) {
    LL res = 0;
    res += (LL) p1.F * p2.S - (LL) p1.S * p2.F;
    res += (LL) p2.F * p3.S - (LL) p2.S * p3.F;
    res += (LL) p3.F * p1.S - (LL) p3.S * p1.F;
    return res;
}

inline bool ccw(const II &a, const II &o, const II &b) {
    return area(a, o, b) > 0;
//    return (LL) (a.F - o.F) * (b.S - o.S) - (LL) (a.S - o.S) * (b.F - o.F) < 0LL;
}

inline bool collinear(II a, II o, II b) {
    return area(a, o, b) == 0;
//    return (LL) (a.F - o.F) * (b.S - o.S) - (LL) (a.S - o.S) * (b.F - o.F) == 0LL;
}

inline LL dist(const II &A, const II &B) {
    return (LL) (B.F - A.F) * (LL) (B.F - A.F) + (LL) (B.S - A.S) * (LL) (B.S - A.S);
}

bool cmp(const II &A, const II &B) {
    if (collinear(pivot, A, B))
        return dist(pivot, A) < dist(pivot, B);
    double d1x = A.F - pivot.F, d1y = A.S - pivot.S;
    double d2x = B.F - pivot.F, d2y = B.S - pivot.S;
    return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("triland.inp", "r", stdin);
    // freopen("input.inp", "r", stdin);
   freopen("triland.out", "w", stdout);
#endif // ONLINE_JUDGE
    // srand(time(NULL));
    sci(n);
    // n = 300;
    p.resize(n);
    f0(i, n) scii(p[i].F, p[i].S);

    // f0(i, n) p[i] = mp(rand() % 1000000000, rand() % 1000000000);
    int p0 = 0;
    f0(i, n) if (p[i].S < p[p0].S || (p[i].S == p[p0].S && p[i].F > p[p0].F)) p0 = i;
    swap(p[0], p[p0]);
    pivot = p[0];
    sort(++p.begin(), p.end(), cmp);
    // Graham Scan:
    cv.pb(p[n - 1]), cv.pb(p[0]), cv.pb(p[1]);
    int i = 2;
    while (i < n) {
        int j = (int) cv.size() - 1;
        if (ccw(cv[j - 1], cv[j], p[i])) cv.pb(p[i++]);
        else cv.pop_back();
    }
    cv.pop_back();
    n = (int) cv.size();
    int A = 0, B = 1, C = 2;
    LL ans = 0;
    while (true) {
        while (true) {
            while (abs(area(cv[A], cv[B], cv[C])) <= abs(area(cv[A], cv[B], cv[(C + 1) % n]))) C = (C + 1) % n;
            if (abs(area(cv[A], cv[B], cv[C])) <= abs(area(cv[A], cv[(B + 1) % n], cv[C]))) {
                B = (B + 1) % n;
                continue;
            } else break;
        }
        maximize(ans, abs(area(cv[A], cv[B], cv[C])));
        A = (A + 1) % n;
        if (A == B) B = (B + 1) % n;
        if (B == C) C = (C + 1) % n;
        if (A == 0) break;
    }
    printf("%.1lf\n", (double) ans / 2);

    // ans = 0;
    // f0(x, cv.size()) f0(y, cv.size()) f0(z, cv.size()) {
    //             maximize(ans, abs(area(cv[x], cv[y], cv[z])));
    //         }
    // printf("%.1lf\n", (double) ans / 2);
//    f0(A, p.size()) f0(B, p.size()) f0(C, p.size())
//                maximize(ans, abs(area(p[A], p[B], p[C])));
//    printf("%.1lf\n", (double) ans / 2);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}