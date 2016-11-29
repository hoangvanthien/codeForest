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
int d, n, m;

struct matrix {
public:
    int cntRow, cntCol;
    vector<vector<LL> > ma;

    matrix() { }

    matrix(int x, int y) {
        cntRow = x, cntCol = y;
        ma.resize(x);
        f0(i, x) ma[i].resize(y);
    }

    matrix operator*(matrix &o) const {
        int _a = cntRow, _b = cntCol, _c = o.cntCol;
        matrix res = matrix(_a, _c);
        f0(i, _a) f0(j, _c) f0(k, _b) res.ma[i][j] = (res.ma[i][j] + ma[i][k] * o.ma[k][j]) % m;
        return res;
    }
};

inline void init(matrix &M, int r, int c) {
    M.ma.resize(r);
    f0(i, r) M.ma[i].resize(c);
    M.cntRow = r, M.cntCol = c;
}

matrix mf, a;


matrix power(int e) {
    if (e == 1) return a;
    matrix temp = power(e / 2);
    if (e % 2 == 0) return temp * temp;
    else return temp * temp * a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (~sciii(d, n, m)) {
        if (d == 0 && n == 0 && m == 0) break;
        mf = matrix(d, 1);
        a = matrix(d, d);
        FOR(i, 0, d - 2) a.ma[i][i + 1] = 1;
        DFOR(j, d - 1, 0) scanf("%lld", &a.ma[d - 1][j]);
        FOR(i, 0, d - 1) scanf("%lld", &mf.ma[i][0]);
        if (n <= d) printf("%lld\n", mf.ma[n - 1][0]);
        else {
            matrix temp = power(n - 1);
            LL ans = 0;
            FOR(i, 0, d - 1) ans = (ans + temp.ma[0][i] * mf.ma[i][0]) % m;
            printf("%lld\n", ans);
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}