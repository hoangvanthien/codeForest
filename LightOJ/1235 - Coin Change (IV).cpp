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

const int N = 25;
const int oo = 1000000007;
int a[20];

void gen(vector<int> &x, vector<int> &y) {
    y.clear();
    y.pb(0);
    forit(it, x) {
        int sz = (int) y.size();
        FOR(i, 0, sz - 1) FOR(j, 1, 2) y.pb(*it * j + y[i]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(T);
    int __test = 0;
    while (T--) {
        scnii(n, k);
        sca(a, n);
        vector<int> A, B, C, D;
        FOR(i, 1, n / 2) A.pb(a[i]);
        FOR(i, n / 2 + 1, n) B.pb(a[i]);
        gen(A, C);
        gen(B, D);
        int flag = false;
        sort(D.begin(), D.end());
        forit(it, C) {
            if (binary_search(D.begin(), D.end(), k - *it)) flag = true;
        }
        printf("Case %d: ", ++__test);
        if (flag) puts("Yes"); else puts("No");
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}