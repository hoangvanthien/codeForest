#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 10002;
const int oo = 1000000007;
int n,m,d1[N],d2[N],d[N];
vector<II> dsk[N], dsk1[N], dsk2[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("gpsduel.inp", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
        int u,v,w1,w2; scanf("%d%d%d%d", &u, &v, &w1, &w2);
        dsk1[v].pb(mp(u,w1));
        dsk2[v].pb(mp(u,w2));
	}
	priority_queue<II> pq;
	pq.push(mp(0,n));
	FOR(i,1,n-1) d1[i] = d2[i] = oo;
	while (pq.size()) {
        II top = pq.top(); pq.pop();
        int u = top.S, du = -top.F;
        if (du != d1[u]) continue;
        forit(it, dsk1[u]) {
            int v = it->F, w = it->S;
            if (d1[v] > d1[u] + w) {
                d1[v] = d1[u] + w;
                pq.push(mp(-d1[v], v));
            }
        }
	}
	pq = priority_queue<II>();
	pq.push(mp(0,n));
	while (pq.size()) {
        II top = pq.top(); pq.pop();
        int u = top.S, du = -top.F;
        if (du != d2[u]) continue;
        forit(it, dsk2[u]) {
            int v = it->F, w = it->S;
            if (d2[v] > d2[u] + w) {
                d2[v] = d2[u] + w;
                pq.push(mp(-d2[v], v));
            }
        }
	}
	FOR(u,1,n) FOR(j,0,(int)dsk1[u].size()-1) {
        int v = dsk1[u][j].F, w1 = dsk1[u][j].S, w2 = dsk2[u][j].S;
        int cnt = 0;
        if (d1[u] + w1 != d1[v]) ++cnt;
        cnt += d2[u] + w2 != d2[v];
        dsk[v].pb(mp(u,cnt));
	}
	pq = priority_queue<II>();
	pq.push(mp(0,1));
	FOR(i,2,n) d[i] = oo;
	while (pq.size()) {
        II top = pq.top(); pq.pop();
        int u = top.S, du = -top.F;
        if (du != d[u]) continue;
        forit(it, dsk[u]) {
            int v = it->F, w = it->S;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(mp(-d[v], v));
            }
        }
	}
	printf("%d\n", d[n]);
}


