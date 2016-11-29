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

LL a, b, c, k, ind;

struct matrix {
    LL ma[3][3];

    matrix() {
        f0(i, 3) f0(j, 3) ma[i][j] = (i == j);
    }

    matrix inline operator*(const matrix &x) {
        matrix res = matrix();
        f0(i, 3) f0(j, 3) {
                LL sum = 0;
                f0(k, 3) sum += ma[i][k] * x.ma[k][j];
                sum %= k;
                res.ma[i][j] = sum;
            }
        return res;
    }
};

matrix m;

matrix power(int n) {
    if (n == 0) return matrix();
    matrix res = power(n / 2);
    if (n % 2 == 0) return res * res;
    else return res * res * m;
}

int f[] = {1, 2, 3};

int main() {
#ifndef ONLINE_JUDGE
    freopen("fib3.inp", "r", stdin);
    freopen("fib3.out", "w", stdout);
#endif // ONLINE_JUDGE

    m = matrix();
    while (~scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &k, &ind)) {
//        vector<LL> v;
//        f0(i, 4) v.pb(i);
//        FOR(i, 4, 100) {
//            if (i % 3 == 1) v.pb(a * v[i - 1] + b * v[i - 2] + c * v[i - 3]);
//            if (i % 3 == 2) v.pb(b * v[i - 1] + c * v[i - 2] + a * v[i - 3]);
//            if (i % 3 == 0) v.pb(c * v[i - 1] + a * v[i - 2] + b * v[i - 3]);
//        }
//        printf("v[%lld] = %lld\n", ind, v[ind] % k);
        if (ind <= 3) {
            printf("%lld\n", ind % k);
            continue;
        }
        m.ma[0][0] = c, m.ma[0][1] = b, m.ma[0][2] = a;
        m.ma[1][0] = (b * c) % k,
        m.ma[1][1] = (b * b) % k + a, m.ma[1][2] = (b * a) % k + c;
        m.ma[2][0] = ((b * c) % k * c) % k + (a * c) % k, m.ma[2][1] =
                ((b * b) % k * c) % k + (a * c) % k + (a * b) % k, m.ma[2][2] =
                (a * a) % k + (c * c) % k + ((a * b) % k * c) % k + b;
        --ind;
        matrix temp = power((int) ind / 3);
        int row = (int) (ind % 3);
        LL ans = 0;
        f0(i, 3) {
            ans = (ans + temp.ma[row][i] * f[i]) % k;
        }
        printf("%lld\n", ans);

    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}