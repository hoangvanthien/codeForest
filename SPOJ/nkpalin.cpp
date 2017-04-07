#include "bits/stdc++.h"

using namespace std;

#define mp make_pair

const int N = 2005;
const int oo = 1000000007;
char T[N];
bool mark[N];
int f[N][N];
pair<int, int> trace[N][N];

int dp(int i, int j) {
    if (i > j) return 0;
    if (trace[i][j] != mp(0, 0)) return f[i][j];
    int res = 0;
    if (T[i] == T[j]) {
        res = dp(i + 1, j - 1) + 2;
        trace[i][j] = mp(i, j);
    } else {
        res = max(dp(i + 1, j), dp(i, j - 1));
        trace[i][j] = f[i + 1][j] > f[i][j - 1] ? trace[i + 1][j] : trace[i][j - 1];
    }
    return f[i][j] = res;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%s", T);
    int n = (int) strlen(T);
    dp(0, n - 1);
    int i = 0, j = n - 1;
    while (i <= j) {
        if (T[i] == T[j]) mark[i] = mark[j] = 1, i++, j--;
        else {
            pair<int, int> p = trace[i][j];
            i = p.first, j = p.second;
        }
    }
    for (int i = 0; i < n; ++i) if (mark[i]) printf("%c", T[i]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}