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
int n, prime[N];
vector<int> fac, pr;
map<int, int> m;

int div(int x) {
    forit(it, pr) {
        int u = *it;
        if ((LL) u * u > (LL) x) return x;
        if (x % u == 0) return u;
    }
    return x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("timso.inp", "r", stdin);
    freopen("timso.out", "w", stdout);
#endif // ONLINE_JUDGE
    FOR(i, 2, N - 1) prime[i] = i;
    FOR(i, 2, N - 1) if (prime[i] == i) {
            for (int j = i; j < N; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    sci(n);
    if (n == 0) {
        puts("10");
        return 0;
    }
    FOR(i, 2, N - 1) if (prime[i] == i) pr.pb(i);
    while (n != 1) {
        if (n < N) {
            fac.pb(prime[n]);
            n /= prime[n];
        } else {
            int temp = div(n);
            fac.pb(temp);
            n /= temp;
        }
    }
//    forit(it, fac) printf("%d ", *it);
    forit(it, fac) m[*it]++;
    vector<int> ans;
    forit(it, m) {
        int divisor = it->F, q = it->S;
        if (divisor > 9) {
            puts("-1");
            return 0;
        }
        if (divisor == 2) {
            int temp = q / 3;
            f1(i, temp) ans.pb(8);
            if (q % 3 == 2) ans.pb(4);
            if (q % 3 == 1) ans.pb(2);
        } else if (divisor == 3) {
            int temp = q / 2;
            f1(i, temp) ans.pb(9);
            if (q % 2 == 1) ans.pb(3);
        } else {
            f1(i, q) ans.pb(divisor);
        }
    }
    sort(ans.begin(), ans.end());
    forit(it, ans) printf("%d", *it);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}