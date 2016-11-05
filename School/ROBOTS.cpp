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
#define M(x,y) Map[mp((x),(y))]

const int N = 100002;

int num[N], low[N], parent[N], d1[N], d2[N], cnt, s1, s2, n, m, pos;
vector<pair<II, int> > dsk[N];
vector<II> bridge;
map<II, int> Map;

void dfs(int u) {
    low[u] = n+1; num[u] = ++cnt;
    forit(it, dsk[u]) if ((*it).S) {
        (*it).S = false;
        int v = (*it).F.F;
        pos = lower_bound(dsk[v].begin(), dsk[v].end(), mp(mp(u,0),0)) - dsk[v].begin();
        dsk[v][pos].S = false;
        if (!parent[v]) {
            parent[v] = u;
            dfs(v);
//            if (low[v] > num[u]) bridge.pb(mp(u,v));
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
}

void dij(int start, int d[]) {
    FOR(i,1,n) d[i] = oo;
    d[start] = 0;
    set<II> s; s.clear();
    s.insert(mp(0, start));
    while (!s.empty()) {
        II top = *(s.begin()); s.erase(s.begin());
        int u = top.S;
        forit(it, dsk[u]) {
            int v = (*it).F.F, w = (*it).F.S;
            if (d[v] > d[u] + w) {
                s.erase(mp(d[v], v));
                d[v] = d[u] + w;
                s.insert(mp(d[v], v));
            }
        }
    }
}

int main() {
	 // freopen("robots.inp", "r", stdin);
	 // freopen("robots.out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        dsk[u].pb(mp(mp(v,w), 1)); dsk[v].pb(mp(mp(u,w), 1));
	}
	FOR(i,1,n) sort(dsk[i].begin(), dsk[i].end());
	scanf("%d%d", &s1, &s2);
    FOR(i,1,n) if (!parent[i]) {
        parent[i] = -1;
        dfs(i);
    }
//    return 0;
    FOR(i,1,n) if (parent[i] != -1 && low[i] >= num[i]) bridge.pb(mp(i, parent[i]));
    int ans = oo;
    dij(s1, d1); dij(s2, d2);
    forit(it, bridge) {
        int temp = max(d1[(*it).F], d2[(*it).S]);
        temp = min(temp, max(d1[(*it).S], d2[(*it).F]));
        ans = min(temp, ans);
    }
    printf("%d", ans);
}
