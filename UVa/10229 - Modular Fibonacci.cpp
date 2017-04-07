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
LL mod = 100000;

struct Matrix {
    LL a = 1, b = 0, c = 1, d = 0;

    Matrix() : a(1), b(0), c(1), d(0) { };

    Matrix(LL _a, LL _b, LL _c, LL _d) : a(_a % mod), b(_b % mod), c(_c % mod), d(_d % mod) { };

    Matrix operator*(const Matrix &M) const {
        return Matrix(a * M.a + b * M.c, a * M.b + b * M.d, c * M.a + d * M.c, c * M.b + d * M.d);
    }
};

Matrix power(int n) {
    if (n == 0) return Matrix(1LL, 0LL, 0LL, 1LL);
    Matrix temp = power(n / 2);
    if (n % 2 == 0) return temp * temp;
    else return temp * temp * Matrix(1, 1, 1, 0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int u, v;
    while (~scanf("%d %d\n", &u, &v)) {
        mod = 1LL << v;
        Matrix x = power(u);
        printf("%lld\n", x.c);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}