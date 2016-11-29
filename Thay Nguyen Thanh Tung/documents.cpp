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
II p[N];
set<II > s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    f1(i, n) {
        scniii(a, b, c);
        if (a + c > b) {
            puts("NO");
            return 0;
        }
        p[i] = mp(a + c, b);
    }
    sort(p + 1, p + n + 1);
    int j = p[1].first;
    int cnt = 0;
    f1(i, n) {
        while (i <= n && p[i].first == j) {
            s.insert(mp(p[i].S, i));
            ++cnt, ++i;
        }
        II v = *s.begin();
        if (v.F < j) {
            puts("NO");
            return 0;
        }
        s.erase(v);
        --cnt;
        if (cnt == 0 && i != n + 1) j = p[i].F;
        else ++j;
        --i;
    }
    while (cnt > 0) {
        II v = *s.begin();
        if (v.F < j) {
            puts("NO");
            return 0;
        }
        s.erase(v);
        ++j, --cnt;
    }
    puts("YES");
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}