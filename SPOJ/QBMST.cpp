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

int d[N],m,n,ans;
vector<II> dsk[N];
void Prim() {
    FOR(i,1,n) d[i] = oo; d[1] = 0;
    priority_queue<II> pq;
    pq.push(mp(0,1));
    while (!pq.empty()) {
        II top = pq.top(); pq.pop();
        int u = top.S, du = -top.F;
        if (d[u] != du) continue;
        ans += du; d[u] = 0;
        forit(it, dsk[u]) {
            int v = (*it).F, w = (*it).S;
            if (d[v] > w) {
                d[v] = w;
                pq.push(mp(-d[v], v));
            }
        }
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
        int x,y,z;
        scanf("%d%d%d", &x, &y, &z);
        dsk[x].pb(mp(y,z));
        dsk[y].pb(mp(x,z));
    }
    Prim();
    printf("%d", ans);
}
