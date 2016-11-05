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

const int N = 100002;
int num[N], low[N], parent[N], root, cnt_children, cnt, n, m;
bool cut[N];
vector<int> dsk[N];
vector<II> bridge;

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            parent[v] = u;
            if (root == u) ++cnt_children;
            dfs(v);
            if (low[v] >= num[u]) cut[u] = true;
            if (low[v] >= num[v]) bridge.pb(mp(u,v));
            low[u] = min(low[u], low[v]);
        } else {
            if (parent[u] != v) low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d %d", &n, &m);
	FOR(i,1,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        dsk[u].pb(v); dsk[v].pb(u);
	}
	FOR(u,1,n) if (num[u] == 0) {
        root = u; cnt_children = 0;
        dfs(u);
        cut[u] = (cnt_children > 1);
	}
	printf("Cut: ");
	FOR(i,1,n) if (cut[i]) printf("%d ", i);
	printf("\nBridge: ");
	forit(it, bridge) printf("%d-%d ", (*it).F, (*it).S);
}
