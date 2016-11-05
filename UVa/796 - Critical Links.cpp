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
int low[N], num[N], parent[N], cnt;
vector<int> dsk[N];
vector<II> bridge;

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    forit(it, dsk[u]) {
        int v = (*it);
        if (num[v] == 0) {
            parent[v] = u;
            dfs(v);
            if (low[v] >= num[v]) {
                if (u<v) bridge.pb(mp(u,v)); else bridge.pb(mp(v,u));
            }
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
	int n;
	while (scanf("%d", &n) != EOF) {
        bridge.clear();
        memset(low, 0, sizeof low);
        memset(num, 0, sizeof num);
        cnt = 0;

        FOR(i,0,n-1) {
            parent[i] = -1;
            dsk[i].clear();
        }
        FOR(i,1,n) {
            int u, _cnt, v;
            scanf("%d (%d)", &u, &_cnt);
            FOR(j,1,_cnt) {
                scanf("%d", &v);
                dsk[u].pb(v);
            }
        }
        FOR(i,0,n-1) if (!num[i]) {
            dfs(i);
        }
        printf("%d critical links\n", bridge.size());
        sort(bridge.begin(), bridge.end());
        forit(it, bridge) printf("%d - %d\n", (*it).F, (*it).S);
        printf("\n");
	}
//	printf("\n");
}
