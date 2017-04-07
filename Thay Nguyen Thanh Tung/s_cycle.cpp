#include "bits/stdc++.h"

using namespace std;

#define loop(i, x, y, b) for(int i = (x), b = ((x) <= (y)); b ? (i <= (y)) : (i >= (y)); i += b ? 1 : -1)
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
#define vi vector<int>
#define vii vector<II >

const int N = 200005;
const int oo = 1000000007;
char T[N];
int n, b[N];

inline void kmpPre(int x, int m) {
    b[0] = -1;
    for (int i = 0, j = -1; i < m;) {
        while (j >= 0 && T[x + i] != T[x + j]) j = b[j];
        ++i, ++j;
        b[i] = j;
    }
}

inline bool kmpComp(int x, int m) {
    for (int i = 0, j = 0, cnt = 0; cnt < 2;) {
        while (j >= 0 && T[i] != T[x + j]) j = b[j];
        ++i, ++j;
        if (j == m) return true;
        if (i == m) {
            i = 0;
            ++cnt;
        }
    }
    return false;
}

bool comp(int m) {
    for (int i = m; i < n; i += m) {
        kmpPre(i, m);
        if (!kmpComp(i, m)) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("s_cycle.inp", "r", stdin);
//    freopen("input.inp", "r", stdin);
    freopen("s_cycle.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%s", T);
    n = (int) strlen(T);
//    n = 200000;
//    f0(i, n) T[i] = 'a';
    vi ans;
    FOR(i, 1, n) if (n % i == 0 && comp(n / i)) ans.pb(i);
    printf("%d\n", (int) ans.size());
    forit(it, ans) printf("%d ", *it);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}