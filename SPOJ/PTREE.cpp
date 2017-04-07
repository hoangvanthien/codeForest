#include "bits/stdc++.h"

using namespace std;
#define mp make_pair

const int N = 205;
const int oo = 1000000007;
int n, a[N], mark[N], p, sz[N], f[N][N][N], trace[N][N][N], did[N][N][N];
vector<int> dsk[N];

void dfs(int u) {
    mark[u] = true;
    sz[u] = 1;
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i];
        if (!mark[v]) dfs(v);
        else {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
            continue;
        }
        sz[u] += sz[v];
    }
}

// Maximum sum of subtree dsk[child]..dsk.back()

int attempt(int u, int am, int child) {
    if (am <= 0) return 0;
    if (child == dsk[u].size()) return -oo;
    if (did[u][am][child]) return f[u][am][child];
    int v = dsk[u][child], res = -oo, _t = 0;
    for (int t = 0; t <= min(sz[v], am); ++t) {
        int tmp = 0;
        if (t > 0) {
            tmp += attempt(v, t - 1, 0);
            tmp += a[v];
        }
        tmp += attempt(u, am - t, child + 1);
        if (tmp > res) {
            res = tmp;
            _t = t;
        }
    }
    trace[u][am][child] = _t;
    did[u][am][child] = 1;
    return f[u][am][child] = res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        if (sz[i] >= p) {
            attempt(i, p - 1, 0);
        }
    int _i = 0, Max = -oo;
    for (int i = 1; i <= n; ++i)
        if (sz[i] >= p && Max < f[i][p - 1][0] + a[i]) {
            Max = f[i][p - 1][0] + a[i];
            _i = i;
        }
    memset(mark, 0, sizeof mark);
    queue<pair<int, pair<int, int> > > q;
    q.push(mp(_i, mp(p - 1, 0)));
    mark[_i] = true;
    while (q.size()) {
        int u = q.front().first, am = q.front().second.first, child = q.front().second.second;
        q.pop();
        if (am <= 0) continue;
        if (child < dsk[u].size()) {
            if (trace[u][am][child] > 0) mark[dsk[u][child]] = 1;
            q.push(mp(u, mp(am - trace[u][am][child], child + 1)));
            q.push(mp(dsk[u][child], mp(trace[u][am][child] - 1, 0)));
        }
    }
    for (int i = 1; i <= n; ++i) if (mark[i]) printf("%d ", i);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}