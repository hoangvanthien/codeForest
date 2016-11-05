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

const int N = 1000005;
const int oo = 1000000007;
set<int> s;
map<int, int> m;
int a[N], n;

bool ok(int len) {
    s.clear();
    m.clear();
    FOR(i, 1, len) {
        s.insert(a[i]);
        m[a[i]]++;
    }
    if (s.size() == 2) return true;
    for (int i = len + 1; i <= n; ++i) {
        m[a[i - len]]--;
        if (m[a[i - len]] == 0) s.erase(a[i - len]);
        m[a[i]]++;
        if (m[a[i]] == 1) s.insert(a[i]);
        if (s.size() == 2) return true;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("candies.inp", "r", stdin);
    freopen("candies.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);

    int l = 2, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            maximize(ans, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d", ans);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}