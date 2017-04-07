#include "bits/stdc++.h"

using namespace std;

const int N = 10005;
const int oo = 1000000007;
int n, m, a[N], low[N], st, fi, trace[N];
bool mark[N];
vector<int> dsk[N], rev[N];

void dfs1(int u) {
    mark[u] = 1;
    for (int v : rev[u]) {
        if (!mark[v]) {
            dfs1(v);
            trace[v] = u;
        }
    }
}

void dfs2(int u) {
    mark[u] = 1;
    low[u] = a[u];
    for (int v : dsk[u]) {
        if (!mark[v] && !trace[v]) {
            dfs2(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], a[v]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d %d %d %d", &n, &m, &st, &fi);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        dsk[u].push_back(v);
        rev[v].push_back(u);
    }
    dfs1(fi);
    vector<int> path;
    for (int u = st; u != 0; u = trace[u]) {
        path.push_back(u);
    }
    memset(trace, 0, sizeof trace);
    for (int i = 0; i < path.size(); ++i) trace[path[i]] = i + 1 < path.size() ? path[i + 1] : oo;
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) a[path[i]] = i + 1;
    for (int i = 1; i <= n; ++i) if (a[i] == 0) a[i] = oo;
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= n; ++i) dfs2(i);
    int Min = oo, ans = 0;
    for (int i = (int) path.size() - 1; i >= 0; --i) {
        if (Min >= i + 1) ++ans;
        Min = min(Min, low[path[i]]);
    }
    printf("%d", ans - 2);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}