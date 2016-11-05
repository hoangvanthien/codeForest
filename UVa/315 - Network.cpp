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

const int N = 102;
int num[N], low[N], parent[N], cnt, root, cntChild, n;
bool cut[N];
vector<int> dsk[N];

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] == 0) {
            parent[v] = u;
            if (u == root) ++cntChild;
            dfs(v);
            if (low[v] >= num[u]) cut[u] = true;
            low[u] = min(low[u], low[v]);
        } else if (parent[u] != v) low[u] = min(low[u], num[v]);
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	while (scanf("%d", &n) && n != 0) {
        FOR(i,1,n) dsk[i].clear();
        int u;
        while (scanf("%d", &u) && u != 0) {
            string s; stringstream ss; int v;
            getline(cin, s);
            ss.str(s);
            while (ss >> v) dsk[u].pb(v), dsk[v].pb(u);
        }
        memset(num, 0, sizeof num); cnt = 0;
        memset(parent, 0, sizeof parent);
        memset(low, 0, sizeof low);
        memset(cut, 0, sizeof cut);
        FOR(i,1,n) if (num[i] == 0) {
            root = i; cntChild = 0;
            dfs(i);
            cut[i] = (cntChild > 1);
        }
        int ans = 0;
        FOR(i,1,n) ans += cut[i];
        printf("%d\n", ans);
	}
}
