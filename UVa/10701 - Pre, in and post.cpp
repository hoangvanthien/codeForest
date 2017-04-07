// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define nl puts("")
#define sci(i) scanf("%d",&i)

const int N = 200005;
const int oo = 1000000007;
int cntTest, n;
char pre[N], in[N];
string post;

void solve(int x, int y, int u, int v) {
    if (x > y || u > v) return;

//    if (x == y) return;
    int lenL = 0, pos = -1;
    FOR(i, u, v) if (in[i] == pre[x]) {
            lenL = i - u;
            pos = i;
            break;
        }
    solve(x + 1, x + lenL, u, u + lenL - 1);
    solve(x + lenL + 1, y, u + lenL + 1, v);
    post += pre[x];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(cntTest);
    while (cntTest--) {
        sci(n);
        scanf("%s %s\n", pre, in);
        post = "";
        solve(0, n - 1, 0, n - 1);
//        reverse(post.begin(), post.end());
        cout << post << endl;
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}