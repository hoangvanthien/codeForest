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
#define vi vector<int>

const int N = 200005;
const int oo = 1000000007;
vi head, tail;

vi flip(int i, int j, vi &x) {
    vi res = x;
    res[i] ^= (1 << j);
    if (i - 1 >= 0) res[i - 1] ^= (1 << j);
    if (i + 1 <= 3) res[i + 1] ^= (1 << j);
    if (j - 1 >= 0) res[i] ^= (1 << (j - 1));
    if (j + 1 <= 3) res[i] ^= (1 << (j + 1));
    return res;
}

map<vi, int> dh, dt;
char T[4];

int main() {
#ifndef ONLINE_JUDGE
    freopen("flip.inp", "r", stdin);
    freopen("flip.out", "w", stdout);
#endif // ONLINE_JUDGE
    f1(i, 4) head.pb(0), tail.pb(15);
    queue<vi > q;
    q.push(head);
    dh[head] = 1;
    while (q.size()) {
        vector<int> u = q.front();
        int du = dh[u];
        q.pop();
        f0(i, 4) f0(j, 4) {
                vi v = flip(i, j, u);
                if (!dh[v]) {
                    dh[v] = du + 1;
                    q.push(v);
                }
            }
    }

    q.push(tail);
    dt[tail] = 1;
    while (q.size()) {
        vector<int> u = q.front();
        int du = dt[u];
        q.pop();
        f0(i, 4) f0(j, 4) {
                vi v = flip(i, j, u);
                if (!dt[v]) {
                    dt[v] = du + 1;
                    q.push(v);
                }
            }
    }
    scni(TT);
    while (TT--) {
        vi des;
        f0(i, 4) {
            scanf("%s", T);
            int t = 0;
            f0(j, 4) if (T[j] == 'T')
                    t += (1 << j);
            des.pb(t);
        }
        int ans = oo;
        if (dh[des]) minimize(ans, dh[des]);
        if (dt[des]) minimize(ans, dt[des]);
        if (ans != oo) printf("%d\n", ans - 1); else puts("Impossible");
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}