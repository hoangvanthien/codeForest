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

int k;

struct matrix {
    vector<vector<LL> > ma;
    int numRow, numCol;

    matrix() { }

    matrix(int nr, int nc, bool read = false) {
        numRow = nr, numCol = nc;
        ma.resize(nr);
        f0(i, nr) ma[i].resize(nc);
        if (read) f0(i, nr) f0(j, nc) scanf("%lld", &ma[i][j]);
    }

    matrix inline operator*(const matrix &x) {
        int m = numRow, n = numCol, k = x.numCol;
        matrix res = matrix(m, k);
        f0(i, m) f0(j, k) {
                LL sum = 0;
                f0(_k, n) sum += ma[i][_k] * x.ma[_k][j];
                res.ma[i][j] = sum;
            }
        return res;
    }

    bool inline operator==(const matrix &x) {
        f0(i, x.numRow) f0(j, x.numCol) {
                if (ma[i][j] != x.ma[i][j]) return false;
            }
        return true;
    }


};

matrix a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("mmc.inp", "r", stdin);
    freopen("mmc.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    while (TT--) {
        sci(k);
        a = matrix(k, k, 1);
        b = matrix(k, k, 1);
        matrix c = matrix(k, 1);
        f0(i, k) c.ma[i][0] = 1;
        b = b * c;
        f1(_, 3) c = a * c;

        if (c == b) puts("YES");
        else puts("NO");
    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}