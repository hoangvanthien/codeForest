// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scni(i) int i; scanf("%d",&i)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)
#define scniiii(a, b, c, d) int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1

const int N = 200005;
const int oo = 1000000007;
int n, ans[N], cnt;
queue<II > q[4];

bool free(int type) {
    return (q[type].empty() || q[type].front().F > cnt);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    f1(i, n) {
        int t;
        char c;
        scanf("%d %c", &t, &c);
        if (c == 'R') q[0].push(mp(t, i));
        else if (c == 'U') q[1].push(mp(t, i));
        else if (c == 'L') q[2].push(mp(t, i));
        else if (c == 'D') q[3].push(mp(t, i));
    }
    f1(i, n) ans[i] = -1;
    while (true) {
        int Min = oo;
        f0(i, 4) if (q[i].size()) minimize(Min, q[i].front().F);
        if (Min > cnt) {
            cnt = Min;
            continue;
        }
        vector<int> v;
        f0(i, 4) {
            int j = (i + 1) % 4;
            if (free(j) && q[i].size() && q[i].front().F <= cnt) v.pb(i);
        }
        if (!v.size()) break; else {
            forit(it, v) {
                int i = *it;
                ans[q[i].front().S] = cnt;
                q[i].pop();
            }
            ++cnt;
        }
    }
    f1(i, n) printf("%d\n", ans[i]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}