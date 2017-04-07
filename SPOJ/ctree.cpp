#include "bits/stdc++.h"

using namespace std;

const int N = 10005;
const int oo = 1000000007;
int n, f[N][4], mark[N], trace[N][4], ans[N];
vector<int> dsk[N];

void dfs(int u) {
    mark[u] = true;
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i];
        if (!mark[v]) dfs(v);
        else {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
        }
    }
}

int dp(int u, int phb) {
    if (f[u][phb] != oo) return f[u][phb];
    int res = oo;
    for (int i = 1; i <= 3; ++i)
        if (i != phb) {
            int sum = 0;
            for (int v : dsk[u]) sum += dp(v, i);
            if (res > sum + i) {
                res = sum + i;
                trace[u][phb] = i;
            }
        }
    return f[u][phb] = res;
}

void dfs2(int u, int phb) {
    ans[u] = trace[u][phb];
    for (int v : dsk[u]) dfs2(v, ans[u]);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    dfs(1);
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= 3; ++j) f[i][j] = oo;
    printf("%d\n", dp(1, 0));
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}