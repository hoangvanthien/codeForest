// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define pb push_back
#define mp make_pair
#define S second
#define II pair<int,int>
#define sci(i) scanf("%d",&i)

const int N = 200005;
const int oo = 1000000007;
int n;
vector<II > point;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    int x;
    f1(i, n) sci(x), point.pb(mp(x, 0));
    f1(i, n) sci(x), point.pb(mp(x, 1));
    sort(point.begin(), point.end());
    int ans = 0;
    f0(i, point.size()) {
        if (i + 1 < point.size() && point[i].S != point[i + 1].S) {
            ++i;
            ++ans;
        }
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}