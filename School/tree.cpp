#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x <<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

using namespace std;

vector<int> dsk[maxN];
bool tt[maxN];
LL d[maxN], f[maxN], ans, cnt[maxN];
map<II, int> lca;
int c[501][501], n;

void dfs(int u) {
    cnt[u] = 1;
    FOR(i,0,(int)dsk[u].size()-1)
    if (!cnt[dsk[u][i]]) {
        dfs(dsk[u][i]);
        cnt[u] += cnt[dsk[u][i]];
    }
    ans += cnt[u] * (n - cnt[u]);
}

int main() {
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    int u, v;
    scanf("%d", &n);
    FOR(i,1,n-1) {
        scanf("%d%d", &u, &v);
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
    dfs(1);
    printf("%lld", ans);
}
