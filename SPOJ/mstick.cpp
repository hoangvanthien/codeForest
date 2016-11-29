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
int n;
II a[N];
vector<int> lis;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    while (TT--) {
        sci(n);
        f1(i, n) scii(a[i].F, a[i].S);
        sort(a + 1, a + 1 + n);
        lis.clear();
        f1(i, n) {
            int pos = lower_bound(lis.begin(), lis.end(), -a[i].S) - lis.begin();
            if (pos == lis.size()) lis.pb(-a[i].S); else lis[pos] = -a[i].S;
        }
        printf("%d\n", (int) lis.size());
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}