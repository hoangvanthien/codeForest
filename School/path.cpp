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

const int N = 1005;
const int oo = 1000000007;
int m, n, d[N][N];
char a[N][N];

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void dij() {
    priority_queue<pair<int, II > > pq;
    f1(i, m) f1(j, n) d[i][j] = oo;
    FOR(i, 2, m - 1) {
        d[i][1] = (a[i][1] == '.');
        pq.push(mp(-d[i][1], mp(i, 1)));
    }
    while (pq.size()) {
        II u = pq.top().S;
        int du = -pq.top().F;
        pq.pop();
        if (du != d[u.F][u.S]) continue;
        f0(i, 8) {
            int x = u.F + dx[i], y = u.S + dy[i];
            if (d[x][y] > d[u.F][u.S] + (a[x][y] == '.') + (a[u.F][u.S] == '.')) {
                d[x][y] = d[u.F][u.S] + (a[x][y] == '.') + (a[u.F][u.S] == '.');
                pq.push(mp(-d[x][y], mp(x, y)));
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(m, n);
    f1(i, m) scanf("%s", a[i] + 1);
    dij();
    int ans = oo;
    FOR(i, 2, m - 1) minimize(ans, d[i][n] + (a[i][n] == '.'));
    printf("%d\n", ans/2);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}