// RM
#include "bits/stdc++.h"

using namespace std;

const int N = 200005;
const int oo = 1000000007;

int n, m, vp[N], t1[N], t2[N], cnt;
vector<int> e[N];

void dfs(int v, int p) {
    vp[v] = p;
    t1[v] = ++cnt;
    for (int i = 0; i < e[v].size(); ++i) {
        int nv = e[v][i];
        if (nv == p) {
            e[v][i] = e[v].back();
            e[v].pop_back();
            --i;
            continue;
        }
        dfs(nv, v);
    }
    t2[v] = ++cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    scanf("%d", &m);
    for (int I = 0; I < m; ++I) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (t1[x] < t1[y] && t2[y] < t2[x]) {
            int l = 0, r = (int) e[x].size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (t1[e[x][mid]] <= t1[y]) l = mid;
                else r = mid - 1;
            }
            cout << e[x][l] << '\n';
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}