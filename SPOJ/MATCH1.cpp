#include "bits/stdc++.h"

using namespace std;

const int N = 205;
const int oo = 1000000007;

int n, m, match[N], mark[N];
vector<int> dsk[N];

bool dfs(int p, int u) {
    if (mark[u]) return false;
    mark[u] = true;
    for (int v : dsk[u]) {
        if (v != p) {
            if (!match[v] || dfs(v, match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d", &m, &n);
    for (int x, y; ~scanf("%d%d", &x, &y); dsk[x].push_back(y + m), dsk[y + m].push_back(x));
    for (int i = 1; i <= m; ++i) {
        memset(mark, 0, sizeof mark);
        dfs(0, i);
    }
    vector<pair<int, int> > answer;
    for (int i = 1; i <= n; ++i)
        if (match[i + m]) answer.push_back(make_pair(match[i + m], i));
    printf("%d\n", (int) answer.size());
    for (pair<int, int> p : answer) printf("%d %d\n", p.first, p.second);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}