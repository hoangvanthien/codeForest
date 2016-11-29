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

const int N = 30005;
const int oo = 1000000007;

struct Vertex {
    int heavy, parent, depth, mark, height, pos, root;

    Vertex() { heavy = parent = depth = mark = height = pos = root = 0; }
};

int n, a[N], bit[N];
vector<int> dsk[N];
Vertex ver[N];

void update(int x, int val) {
    while (x <= n) {
        bit[x] += val;
        x += x & (-x);
    }
}

int getSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= x & (-x);
    }
    return sum;
}

int getSum(int x, int y) {
    if (x > y) swap(x, y);
    return getSum(y) - getSum(x - 1);
}

void dfs(int u) {
    ver[u].mark = true;
    int Max = -1, v_ = 0;
    forit(it, dsk[u]) {
        int v = *it;
        if (!ver[v].mark) {
            ver[v].parent = u;
            ver[v].depth = ver[u].depth + 1;
            dfs(v);
            ver[u].height = ver[v].height + 1;

            if (ver[v].height > Max) {
                Max = ver[v].height;
                v_ = v;
            }
        }
    }
    ver[u].heavy = v_;
}

void hld() {
    dfs(1);
    int cnt = 0;
    f1(i, n) if (ver[i].parent == 0 || ver[ver[i].parent].heavy != i) {
            int x = i;
            while (x != 0) {
                ver[x].root = i;
                ver[x].pos = ++cnt;
                x = ver[x].heavy;
            }
        }
    f1(i, n) update(ver[i].pos, a[i]);
}

int getLength(int x, int y) {
    if (ver[x].root == ver[y].root) return getSum(ver[x].pos, ver[y].pos);
    if (ver[ver[x].root].depth > ver[ver[y].root].depth) swap(x, y);
    int y_ = ver[y].root;
    int py = ver[y_].parent;
    return getSum(ver[y].pos, ver[y_].pos) + getLength(x, py);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    f1(_, TT) {
        memset(a, 0, sizeof a);
        memset(bit, 0, sizeof bit);
        sci(n);
        f1(i, n) dsk[i].clear();
        f1(i, n) ver[i] = Vertex();
        sca(a, n);
        f1(i, n - 1) {
            scnii(x, y);
            ++x, ++y;
            dsk[x].pb(y);
            dsk[y].pb(x);
        }
        hld();
        printf("Case %d:\n", _);
        scni(cntQuery);
        while (cntQuery--) {
            scniii(type, x, y);
            if (type == 0) {
                ++x, ++y;
                printf("%d\n", getLength(x, y));
            } else {
                ++x;
                update(ver[x].pos, y - a[x]);
                a[x] = y;
            }
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}