#include "bits/stdc++.h"

using namespace std;


const int N = 405;
const int oo = 1000000007;
int n, mark[N], f[N];
vector<int> dsk[N];

void dfs(int u) {
    mark[u] = true;
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i];
        if (mark[v]) {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
            continue;
        }
        dfs(v);
    }
}

bool cmp(const int x, const int y) { return f[x] > f[y]; }

int dp(int u) {
    if (f[u]) return f[u];
    if (dsk[u].size() == 0) return f[u] = 1;
    for (int i = 0; i < dsk[u].size(); ++i) dp(dsk[u][i]);
    sort(dsk[u].begin(), dsk[u].end(), cmp);
    int res = 0;
    for (int i = 0; i < dsk[u].size(); ++i) res = max(res, f[dsk[u][i]] + i);
    return f[u] = res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int x, y, z; ~scanf("%d %d", &x, &y);) {
        while (y--) {
            scanf("%d", &z);
            dsk[x].push_back(z);
            dsk[z].push_back(x);
        }
    }
    dfs(1);
    printf("%d\n", dp(1));
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}