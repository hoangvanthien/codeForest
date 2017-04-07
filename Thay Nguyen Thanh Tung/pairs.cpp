// RM
#include "bits/stdc++.h"

using namespace std;

const int N = 200005;
const int oo = 1000000007;
int n;
pair<int, int> p[N];
long long ans;

void solve() {
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        while (i + 1 < n && p[i].first == p[i + 1].first) ++i, ++cnt;
        ans += (long long) cnt * (cnt - 1) / 2;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &p[i].first, &p[i].second);

    sort(p, p + n);
    solve();
    for (int i = 0; i < n; ++i) swap(p[i].first, p[i].second);
    sort(p, p + n);
    solve();
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        while (i + 1 < n && p[i] == p[i + 1]) ++i, ++cnt;
        ans -= (long long) cnt * (cnt - 1) / 2;
    }
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}