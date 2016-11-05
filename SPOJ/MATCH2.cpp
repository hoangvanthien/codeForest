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

const int N = 205;
int c[N][N], fx[N], fy[N], ass1[N], ass2[N], trace[N], n, start, finish;
II d[N];
queue<int> q;
int getC (int x, int y) {
    return c[x][y] - fx[x] - fy[y];
}
void initBFS() {
    q = queue<int>(); q.push(start);
    memset(trace, 0, sizeof trace);
    FOR(v,1,n) d[v] = mp(getC(start, v), start);
    finish = 0;
}
void BFS() {
    do {
        int u = q.front(); q.pop();
        FOR(v,1,n) if (trace[v] == 0) {
            int w = getC(u,v);
            if (w == 0) {
                trace[v] = u;
                if (ass2[v] == 0) {
                    finish = v;
                    return;
                } else q.push(ass2[v]);
            }
            if (d[v].F > w) d[v] = mp(w, u);
        }
    } while (!q.empty());
}
void Adjust() {
    int delta = oo;
    FOR(v,1,n) if (trace[v] == 0) delta = min(delta, d[v].F);
    fx[start] += delta;
    FOR(v,1,n) if (trace[v]) {
        fy[v] -= delta; fx[ass2[v]] += delta;
    } else d[v].F -= delta;
    FOR(v,1,n) if (trace[v] == 0 && d[v].F == 0) {
        trace[v] = d[v].S;
        if (ass2[v] == 0) {
            finish = v;
            return;
        } else q.push(ass2[v]);
    }
}
void Enlarge() {
    do {
        int u = trace[finish], next = ass1[u];
        ass1[u] = finish;
        ass2[finish] = u;
        finish = next;
    } while (finish);
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d", &n);
	FOR(u,1,n) FOR(v,1,n) c[u][v] = oo;
	int x,y,z;
	while (scanf("%d%d%d", &x, &y, &z) != EOF) c[x][y] = z;
	FOR(u,1,n) {
        start = u;
        initBFS();
        do {
            BFS();
            if (!finish) Adjust();
        } while (!finish);
        Enlarge();
	}
	int w = 0;
	vector<II> ans;
	FOR(u,1,n) if (c[u][ass1[u]] < oo) ans.pb(mp(u, ass1[u])), w += c[u][ass1[u]];
	printf("%d\n", w);
	forit(it, ans) printf("%d %d\n", it->F, it->S);
}
