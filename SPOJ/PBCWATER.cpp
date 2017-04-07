#include "bits/stdc++.h"

using namespace std;

const int N = 105;
const int oo = 1000000007;

int m, n, a[N][N], Min, mark[N][N], cnt, k;
pair<int, int> pos[N * 10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void loang(int x, int y) {
    if (mark[x][y]) return;
    mark[x][y] = k;
    ++cnt;
    for (int i = 0; i < 4; ++i) {
        if (a[x + dx[i]][y + dy[i]] != a[x][y]) Min = min(Min, a[x + dx[i]][y + dy[i]]);
        else loang(x + dx[i], y + dy[i]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            pos[a[i][j]] = make_pair(i, j);
        }
    }
    queue<int> q;
    for (int i = 1; i <= 1000; ++i) if (pos[i].first) q.push(i);
    int ans = 0;
    while (q.size() != 1) {
        k = 0;
        memset(mark, 0, sizeof mark);
        int h = q.front();
        q.pop();
        vector<int> v;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] == h) {
                    cnt = 0;
                    Min = oo;
                    ++k;
                    loang(i, j);
                    v.push_back(Min);
                    ans += max(Min - h, 0) * cnt;
                }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) if (mark[i][j]) a[i][j] = max(a[i][j], v[mark[i][j] - 1]);

    }
    printf("%d", ans);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}