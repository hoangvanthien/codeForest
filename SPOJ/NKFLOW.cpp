
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

const int N = 1002;
int c[N][N], f[N][N], trace[N], delta[N], m, n, s, t;

bool FindPath() {
    memset(trace, 0, sizeof trace);
    queue<int> q; q.push(s);
    trace[s] = s;
    delta[s] = oo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FOR(v,1,n) if (trace[v] == 0) {
            if (c[u][v] > f[u][v]) {
                trace[v] = u;
                delta[v] = min(delta[u], c[u][v] - f[u][v]);
                q.push(v);
            } else
                if (f[v][u] > 0) {
                    trace[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    q.push(v);
                }
        }
    }
    return (trace[t] != 0);
}
void IncFlow() {
    int v = t;
    while (v != s) {
        int u = trace[v];
        if (u > 0) f[u][v] += delta[t]; else {
            u = -u;
            f[v][u] -= delta[t];
        }
        v = u;
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d%d%d%d", &n, &m, &s, &t);
	FOR(i,1,m) {
	    int x,y,z; scanf("%d %d %d", &x, &y, &z);
	    c[x][y] += z;
	}
	while (FindPath()) IncFlow();
	int w  = 0;
	FOR(i,1,n) if (f[s][i] > 0) w += f[s][i];
	printf("%d", w);
}
