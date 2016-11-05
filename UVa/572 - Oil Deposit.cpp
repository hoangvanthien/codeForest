// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define scii(a, b) scanf("%d%d", &a, &b)

const int N = 105;
const int oo = 1000000007;
int m, n;
char a[N][N];
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
bool mark[N][N];
int cnt;

bool valid(int x, int y) { return 1 <= x && x <= m && 1 <= n && y <= n; }

void dfs(int x, int y) {
    mark[x][y] = 1;
    f0(i, 8) {
        int u = x + dx[i], v = y + dy[i];
        if (valid(u, v) && !mark[u][v] && a[u][v] == '@') dfs(u, v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    while (1) {
        scii(m, n);
        if (m == 0 && n == 0) break;
        scanf("\n");
        f1(i, m) f1(j, n + 1) scanf("%c", &a[i][j]);
        memset(mark, 0, sizeof mark);
        cnt = 0;
        f1(i, m) f1(j, n) if (a[i][j] == '@' && !mark[i][j]) {
                    dfs(i, j);
                    ++cnt;
                }
        printf("%d\n", cnt);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}