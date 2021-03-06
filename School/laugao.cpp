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

const int N = 50005;
const int oo = 1000000007;
int m, n, prime[N];
vector<int> fac, pr;

bool check(int x) {
    if (x <= 1) return false;
    forit(it, pr) {
        int u = *it;
        if ((LL) u * u > (LL) x) return true;
        if (x % u == 0) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("laugao.inp", "r", stdin);
   freopen("laugao.out", "w", stdout);
#endif // ONLINE_JUDGE
    FOR(i, 2, N - 1) prime[i] = i;
    FOR(i, 2, N - 1) if (prime[i] == i) {
            for (int j = i; j < N; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    FOR(i, 2, N - 1) if (prime[i] == i) pr.pb(i);
    scii(n, m);
    int k, t;
    FOR(i, 0, 10000) if (check(m - i)) {
            k = m - i;
            break;
        }
    printf("%d ", k);
    k %= (n * 2);
    if (k >= n) t = k - n;
    else t = n - k;
    printf("%d", t);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}