#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
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
#define lb lower_bound
#define ub upper_bound

map<II, LL> total;
int n,m,K,parent[maxN],low[maxN],cnt,number[maxN];
vector<pair<int, bool> > dsk[maxN];
vector<II> lis;

void init() {
	scanf("%d%d%d", &n, &m, &K);
	FOR(i,1,m) {
		int u,v,c;
		scanf("%d%d", &u, &v);
		LL &temp = total[mp(u,v)];
		if (temp != 0) {
			++temp;
			total[mp(v,u)]++;
			continue;
		} else temp = 1, total[mp(v,u)] = 1;
		dsk[u].pb(mp(v,true));
		dsk[v].pb(mp(u,true));
	}
	FOR(i,1,n) sort(dsk[i].begin(), dsk[i].end());
}

void visit(int u) {
	number[u] = ++cnt; low[u] = n+1;
	cnt[u] = 1;
	forit(it, dsk[u])
	if ((*it).S) {
		(*it).S = false;
		int v = (*it).F;
		int pos = lower_bound(dsk[v].begin(), dsk[v].end(), mp(u,false)) - dsk[v].begin();
		dsk[v][pos].S = false;
		if (!parent[v]) {
			parent[v] = u;
			visit(v);
			cnt[u] += cnt[v];
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], number[v]);
	}
}

void Create() {
	FOR(v,1,n)
	if (parent[v] != -1 && low[v] >= number[v]) {
		int cnt = total[mp(parent[v], v)];
		if (cnt == 1) lis.pb(mp(parent[v], v));
	}
	sort(lis.begin(), lis.end());
}

int main() {
//	 freopen("travel.inp", "r", stdin);
//	 freopen("travel.out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	init();
	FOR(u,1,n) if (!parent[u]) {
		parent[u] = -1;
		visit(u);
	}
	Create();
	LL ans = 0;
	FOR(i,0,(int)lis.size()-1) {
		if (i + K - 1 >= (int)lis.size()) break;
		int j = i+K-1;
		//while (j < lis.size() && lis[i] == lis[j]) ++j;
		//if (j == lis.size()) break;
        if (i == 0) ans += (n-cnt[lis[i].F]+1) * (cnt[lis[j].S]);
        else ans += (lis[i].F-lis[i-1].F)*(n-lis[j].S+1);
//		}
	}
	printf("%lld", ans);
}
