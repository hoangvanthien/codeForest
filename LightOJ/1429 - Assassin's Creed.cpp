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
#define refresh(x) memset(x,0,sizeof x)

const int N = 1005;
const int oo = 1000000007;

int n, m, parent[N], cntDFS, cntSCC, low[N], num[N], scc[N];
vector<int> dsk[N], g2[N], g3[N];
stack<int> stk;
bool onStack[N];

inline void dfs(int u) {
    num[u] = low[u] = ++cntDFS;
    stk.push(u);
    onStack[u] = true;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            dfs(v);
            minimize(low[u], low[v]);
        } else if (onStack[v]) minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ++cntSCC;
        int v;
        do {
            v = stk.top();
            stk.pop();
            onStack[v] = false;
            scc[v] = cntSCC;
        } while (u != v);
    }
}

inline bool fap(int u) { // use DFS to find augmenting path
    if (num[u]) return false;
    num[u] = true;
    forit(it, g3[u]) {
        int v = *it;
        if (!parent[v] || fap(parent[v])) {
            parent[v] = u;
            return true;
        }
    }
    return false;
}

inline void dfs(const int &root, int u) {
    num[u] = true;
    forit(it, g2[u]) if (!num[*it]) {

            g3[root].pb(*it);
            dfs(root, *it);
        }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    f1(_, TT) {
        scii(n, m);
        cntDFS = cntSCC = 0;
        f1(i, n) {
            dsk[i].clear(), g2[i].clear(), g3[i].clear();
            num[i] = 0;
        }

        f1(i, m) {
            scnii(x, y);
            dsk[x].pb(y);
        }
        f1(i, n) if (num[i] == 0) dfs(i);
        f1(i, n) forit(it, dsk[i]) {
                int u = scc[i], v = scc[*it];
                if (u != v) g2[u].pb(v);
            }

        int cnt = 0;
        n = cntSCC;

        f1(i, n) {
            f1(j, n) num[j] = false;
            dfs(i, i);
        }
        f1(i, n) parent[i] = 0;
        f1(i, n) {
            f1(j, n) num[j] = false;
            cnt += fap(i);
        }
        printf("Case %d: %d\n", _, n - cnt);
    }
}