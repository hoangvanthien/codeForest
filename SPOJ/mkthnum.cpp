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

const int N = 100005;
const int oo = 1000000007;
int n, a[N];
vector<int> T[N * 4];

void init(int node, int l, int r) {
    if (l == r) {
        T[node].pb(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    init(lc, l, mid);
    init(rc, mid + 1, r);
    T[node].resize(r - l + 1);
    merge(T[lc].begin(), T[lc].end(), T[rc].begin(), T[rc].end(), T[node].begin());
}

int query(int node, int l, int r, int i, int j, int v) {
    if (i > r || j < l) return 0;
    if (i <= l && r <= j) {
        int res = lower_bound(T[node].begin(), T[node].end(), v) - T[node].begin();
        return res;
    }
    int mid = (l + r) / 2;
    return query(lc, l, mid, i, j, v) + query(rc, mid + 1, r, i, j, v);
}

map<int, int> pos;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int cq;
    scii(n, cq);
    sca(a, n);
    vector<int> v;
    f1(i, n) pos[a[i]] = i, v.pb(a[i]);
    sort(v.begin(), v.end());
    init(1, 1, n);
    int la = 0;
    while (cq--) {
        scniii(i, j, k);
        int ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            int _m = (l + r) / 2;
            int mid = v[_m - 1];
            int temp = query(1, 1, n, i, j, mid);
            if (temp + 1 == k && i <= pos[mid] && pos[mid] <= j) {
                ans = mid;
                break;
            }
            if (temp + 1 > k) r = _m - 1;
            else l = _m + 1;
        }
        printf("%d\n", ans);

    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}