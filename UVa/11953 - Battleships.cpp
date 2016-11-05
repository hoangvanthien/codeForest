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
#define lc node*2
#define rc node*2+1

const int N = 205;
const int oo = 1000000007;
int cntTest, n, cntX;
char a[N][N];
bool mark[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= n; }

void dfs(int x, int y) {
    cntX += a[x][y] == 'x';
    mark[x][y] = true;
    f0(i, 4) {
        int u = x + dx[i], v = y + dy[i];
        if (valid(u, v) && a[u][v] != '.' && !mark[u][v]) dfs(u, v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int ___T = 0;
    sci(cntTest);
    while (cntTest--) {
        ++___T;
        sci(n);
        scanf("\n");
        f1(i, n) f1(j, n + 1) scanf("%c", &a[i][j]);
        int ans = 0;
        memset(mark, 0, sizeof mark);
        f1(i, n) f1(j, n) if (!mark[i][j] && a[i][j] != '.') {
                    cntX = 0;
                    dfs(i, j);
                    if (cntX > 0) ++ans;
                }
        printf("Case %d: %d\n", ___T, ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}