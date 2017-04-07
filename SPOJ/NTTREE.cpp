#include "bits/stdc++.h"

using namespace std;

const int N = 10005;
const int oo = 1000000007;
int n, mark[N], sz[N], parent[N];
vector<int> dsk[N];
vector<pair<pair<int, int>, int> > edge;

void dfs(int u) {
    mark[u] = true;
    sz[u] = 1;
    for (int i = 0; i < dsk[u].size(); ++i) {
        int v = dsk[u][i];
        if (mark[v]) {
            dsk[u][i] = dsk[u].back();
            dsk[u].pop_back();
            --i;
            continue;
        }
        dfs(v);
        sz[u] += sz[v];
        parent[v] = u;
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
        ++x, ++y;
        edge.push_back(make_pair(make_pair(x, y), z));
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    dfs(1);
    long long ans = 0;
    for (int i = 0; i < edge.size(); ++i) {
        int x = edge[i].first.first, y = edge[i].first.second, w = edge[i].second;
        if (parent[x] == y) swap(x, y);
        ans += (long long) sz[y] * (n - sz[y]) * w;
    }
    printf("%lld", ans);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}