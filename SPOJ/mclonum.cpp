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

const int N = 65;
const int oo = 1000000007;
int n, cnt[N];
char T[N];
vector<int> a, b, c;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%s", T);
    n = (int) strlen(T);
    f0(i, n) a.pb(T[i] - '0');
    scanf("%s", T);
    f0(i, n) b.pb(T[i] - '0');
    f0(i, n) cnt[b[i]]++;
    bool geq = false;
    DFOR(k, n, 0) {
        f0(i, n) {
            int lim = geq ? 0 : a[i];
            if (i == k && !geq) lim = a[i] + 1;
            if (lim == 0 && i == 0) ++lim;
            FOR(j, lim, 9) if (cnt[j]) {
                    --cnt[j];
                    c.pb(j);
                    break;
                }
            if (c.size() != i + 1) break;
            if (c.size() && c.back() > a[i]) geq = true;
        }
        if (c.size() != a.size()) {
            geq = false;
            c.clear();
            memset(cnt, 0, sizeof cnt);
            f0(i, n) cnt[b[i]]++;
            continue;
        } else {
            forit(it, c) printf("%d", *it);
            nl;
            c.pb(-1);
            break;
        }
    }
    if (c.empty() || c.back() != -1) puts("0");
    c.clear();
    memset(cnt, 0, sizeof cnt);
    f0(i, n) cnt[b[i]]++;
    bool l = false;
    DFOR(k, n - 1, 0) {
        f0(i, n) {
            int lim = l ? 9 : a[i];
            if (i == k && !l) lim = a[i] - 1;
            DFOR(j, lim, 0 + (i == 0)) if (cnt[j]) {
                    --cnt[j];
                    c.pb(j);
                    break;
                }
            if (c.size() != i + 1) break;
            if (c.back() < a[i]) l = true;
        }
        if (c.size() != a.size() || !l) {
            l = false;
            c.clear();
            memset(cnt, 0, sizeof cnt);
            f0(i, n) cnt[b[i]]++;
            continue;
        } else {
            forit(it, c) printf("%d", *it);
            nl;
            return 0;
        }
    }
    puts("0");
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}