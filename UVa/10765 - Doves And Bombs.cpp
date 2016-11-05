#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define new0(x) memset(x, 0, sizeof x)

const int N = 100002;
int num[N], low[N], parent[N], inc[N], cnt, root, cntChild;
bool cut[N];
vector<int> dsk[N];
vector<II> ans;

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            parent[v] = u;
            if (u == root) ++cntChild;
            dfs(v);
            if (low[v] >= num[u]) cut[u] = true, inc[u]++;
            low[u] = min(low[u], low[v]);
        } else if (parent[u] != v) low[u] = min(low[u], num[v]);
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int n,k,u,v;
	while (scanf("%d %d", &n, &k) && n != 0 && k != 0) {
        FOR(i,0,n-1) dsk[i].clear(), parent[i] = -1;
        new0(cut); new0(num); new0(low); new0(inc);
        cnt = 0;
        while (scanf("%d %d", &u, &v) && u != -1 && v != -1) {
            dsk[u].pb(v);
            dsk[v].pb(u);
        }
        FOR(i,0,n-1) if (num[i] == 0) {
            root = i; cntChild = 0;
            dfs(i);
            cut[i] = cntChild > 1;
        }
        ans.clear();
        FOR(i,0,n-1) if (cut[i]) ans.pb(mp(inc[i]+1, -i)); else ans.pb(mp(1, -i));
        sort(ans.begin(), ans.end());
        for(int i = n-1; i >= 0 && k > 0; --i, --k) printf("%d %d\n", -ans[i].S, ans[i].F);
        printf("\n");
	}
}
