// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define pb push_back
#define F first
#define S second
#define II pair<int,int>
#define nl puts("")
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define scni(i) int i; scanf("%d",&i)

const int N = 20005;
int c, n, b[N];
II a[N];
vector<int> lis;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(c, n);
    f1(i, n*c) scii(a[i].F, a[i].S);
    vector<int> v;
    f1(i, c) v.pb(i);
    int ans = n*c;
    do {
        f1(i, n*c) b[i] = v[a[i].F - 1] * 1000 + a[i].S;
        lis.clear();
        f1(i, n*c) {
            int pos = lower_bound(lis.begin(), lis.end(), b[i]) - lis.begin();
            if (pos == lis.size()) lis.pb(b[i]); else lis[pos] = b[i];
        }
        ans = min(ans, n*c - (int) lis.size());
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}