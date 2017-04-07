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

const int N = 50005;
const int oo = 1000000007;
int n, m, lcp[N], phi[N], sa[N], ra[N], tmpRA[N], k;
char T[N];

inline int getRank(int x) { return x >= n ? 0 : ra[x]; }

bool cmp(const int &x, const int &y) { return mp(getRank(x), getRank(x + k)) < mp(getRank(y), getRank(y + k)); }

int main() {
#ifndef ONLINE_JUDGE
//    freopen("dtksub.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("dtksub.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, m);
    if (m == 1) {
        printf("%d\n", n);
        return 0;
    }
    --m;
    scanf("%s", T);
    T[n++] = '$';
    f0(i, n) sa[i] = i, ra[i] = (int) T[i];
    for (k = 1; k < n; k <<= 1) {
        sort(sa, sa + n, cmp);
        tmpRA[sa[0]] = 0;
        int r = 0;
        f1(i, n - 1) tmpRA[sa[i]] = (getRank(sa[i - 1]) == getRank(sa[i]) &&
                                     getRank(sa[i - 1] + k) == getRank(sa[i] + k)) ? r : ++r;
        f0(i, n) ra[i] = tmpRA[i];
    }

    phi[sa[0]] = -1;
    f1(i, n - 1) phi[sa[i]] = sa[i - 1];
    int len = 0;
    f0(i, n) {
        if (phi[i] == -1) {
            lcp[i] = 0;
            continue;
        }
        while (T[i + len] == T[phi[i] + len]) ++len;
        lcp[i] = len;
        len = max(len - 1, 0);
    }
//    f0(i, n) printf("%d %s\n", lcp[sa[i]], T + sa[i]);
    vector<int> v;
    f0(i, n) v.pb(lcp[sa[i]]);
    deque<int> dq;
    int ans = 0;
    f0(i, n) {
        while (dq.size() && i - dq.front() + 1 > m) dq.pop_front();
        while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
        dq.pb(i);
        if (i >= m) maximize(ans, v[dq.front()]);
    }
    printf("%d\n", ans);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}