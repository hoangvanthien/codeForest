// RM
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
int n, a[N], f[N], b[N];
bool nosol[N], inf[N];
map<int, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("accomp.inp", "r", stdin);
   freopen("accomp.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    FOR(i, 2, n) {
        if (a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
        if (a[i] < a[i - 1]) f[i] = f[i - 1] - 1;
        if (a[i] == a[i - 1]) f[i] = f[i - 1];
    }

    f1(i, n) if (f[i] != 0) {
            if ((a[i] - a[1]) % f[i]) {
                nosol[i] = true;
                continue;
            }
            b[i] = (a[i] - a[1]) / f[i];
        }
    f1(i, n) if (f[i] == 0 && a[i] != a[1]) nosol[i] = true;
    f1(i, n) if (f[i] == 0 && a[i] == a[1]) inf[i] = true;
    f1(i, n) if (!nosol[i] && !inf[i]) {
            cnt[b[i]]++;
        }
    int ans = 0, k = 0;
    forit(it, cnt) {
        if (ans < it->S) {
            ans = it->S;
            k = it->F;
        }
    }
    f1(i, n) ans += inf[i];
    printf("%d\n%d", ans, k);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}