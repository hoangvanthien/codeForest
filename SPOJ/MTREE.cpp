#include "bits/stdc++.h"

using namespace std;

const int N = 100005;
const int oo = 1000000007;
int n, mark[N];
long long f[N], g[N];
vector<pair<int, int> > dsk[N];

void dfs(int u) {
    mark[u] = true;
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i].first, w = dsk[u][i].second;
        if (mark[v]) {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
            continue;
        }
        dfs(v);
        f[u] = (f[u] + (f[v] + 1) * w) % oo;
    }
    long long sumf = f[u];
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i].first, w = dsk[u][i].second;
        g[u] = (g[u] + ((f[v] * w + w) % oo) * ((sumf + oo - (f[v] + 1) * w) % oo)) % oo;
        sumf -= (f[v] + 1) * w;
        sumf = (sumf + oo) % oo;
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        dsk[x].push_back(make_pair(y, z));
        dsk[y].push_back(make_pair(x, z));
    }
    dfs(1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + f[i] + g[i]) % oo;
    printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}