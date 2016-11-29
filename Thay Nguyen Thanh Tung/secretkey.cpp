// RM
#include "bits/stdc++.h"

using namespace std;

const int N = 200005;
const int oo = 1000000007;
int n, a[N];
vector<int> b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] += i;
    }
    for (int i = 1; i <= n; ++i) {
        int pos = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        if (pos == b.size()) b.push_back(a[i]);
        else b[pos] = a[i];
    }
    cout << b.size();
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}