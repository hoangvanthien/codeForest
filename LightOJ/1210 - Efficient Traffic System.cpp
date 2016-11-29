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

const int N = 20005;
const int oo = 1000000007;
int n, m, low[N], num[N], cntDFS, cntSCC, scc[N], inDeg[N], outDeg[N];
vector<int> dsk[N];
stack<int> stk;
map<II, bool> Map;

void dfs(int u) {
    low[u] = num[u] = ++cntDFS;
    stk.push(u);
    forit(it, dsk[u]) {
        int v = *it;
        if (scc[v]) continue;
        if (num[v] == 0) {
            dfs(v);
            minimize(low[u], low[v]);
        } else
            minimize(low[u], num[v]);
    }
    if (num[u] == low[u]) {
        int v;
        ++cntSCC;
        do {
            v = stk.top();
            stk.pop();
            scc[v] = cntSCC;
        } while (u != v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    f1(_, TT) {
        scii(n, m);
        f1(i, n) {
            dsk[i].clear();
            low[i] = num[i] = scc[i] = inDeg[i] = outDeg[i] = 0;
        }
        Map.clear();
        cntDFS = cntSCC = 0;
        f1(i, m) {
            scnii(x, y);
            dsk[x].pb(y);
        }
        f1(i, n) if (num[i] == 0) dfs(i);
        if (cntSCC == 1) {
            printf("Case %d: 0\n", _);
            continue;
        }
        f1(i, n) {
            forit(it, dsk[i]) if (scc[i] != scc[*it]) {
                    Map[mp(scc[i], scc[*it])] = true;
                }
        }
        forit(it, Map) {
            int x = it->F.F, y = it->F.S;
            inDeg[y]++, outDeg[x]++;
        }
        int ans = 0, cnt = 0;
        f1(i, cntSCC) {
            if (inDeg[i] == 0) ++ans;
            if (outDeg[i] == 0) ++cnt;
        }
        maximize(ans, cnt);

        printf("Case %d: %d\n", _, ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}