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

const int N = 1000005;
const int oo = 1000000007;
int k, x, y, trace[N], lt[10], n;

inline int firstDigit(int x) {
    if (x == 0) return 0;
    int res = 0;
    while (x) res = x % 10, x /= 10;
    return res;
}

inline int cntDigit(int x) {
    if (x == 0) return 1;
    int res = 0;
    while (x) res++, x /= 10;
    return res;
}

inline int spin(int x) {
    int fir = firstDigit(x), c = cntDigit(x);
    x -= fir * lt[c - 1];
    x = x * 10 + fir;
    return x;
}

void bfs() {
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == y) break;
        if (u + 1 <= n && trace[u + 1] == 0) {
            trace[u + 1] = u;
            q.push(u + 1);
        }
        int temp = spin(u);
        if (temp <= n && trace[temp] == 0) {
            trace[temp] = u;
            q.push(temp);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cxy.inp", "r", stdin);
   freopen("cxy.out", "w", stdout);
#endif // ONLINE_JUDGE
    sciii(k, x, y);
    lt[0] = 1;
    FOR(i, 1, 10) lt[i] = lt[i - 1] * 10;
    n = lt[k];
    bfs();
    vector<int> ans;
    while (y != x) {
        ans.pb(y);
        y = trace[y];
    }
    ans.pb(x);
    printf("%d\n", (int) ans.size() - 1);
    forrit(it, ans) printf("%d\n", *it);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}