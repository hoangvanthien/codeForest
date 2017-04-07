#include "bits/stdc++.h"

using namespace std;

const int N = 1005;
const int oo = 1000000007;
int n, f[N];
vector<pair<int, int> > dsk[N];

void dfs(int u) {
    if (dsk[u].size() == 0) {
        f[u] = oo;
        return;
    }
    int sum = 0;
    for (pair<int, int> p : dsk[u]) {
        dfs(p.first);
        sum += min(f[p.first], p.second);
    }
    f[u] = sum;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) dsk[i].clear();
        memset(f, 0, sizeof f);
        for (int i = 2; i <= n; ++i) {
            int v, w;
            scanf("%d %d", &v, &w);
            dsk[v].push_back(make_pair(i, w));
        }
        dfs(1);
        if (f[1] == oo) printf("0.00\n");
        else printf("%d.00\n", f[1]);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}