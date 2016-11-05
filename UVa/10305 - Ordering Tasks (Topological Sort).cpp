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
int deg[N], m,n;
vector<int> ans, dsk[N];

void BFS() {
    queue<int> q;
    FOR(i,1,n) if (deg[i] == 0) {
        q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.pb(u);
        forit(it, dsk[u]) if (deg[*it] > 0){
            --deg[*it];
            if (deg[*it] == 0) q.push(*it);
        }
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	while (scanf("%d %d", &n, &m) && !(m==0 && n == 0)) {
        memset(deg, 0, sizeof deg);
        ans.clear();
        FOR(i,1,n) dsk[i].clear();
        FOR(i,1,m) {
            int x,y;
            scanf("%d%d", &x, &y);
            dsk[x].pb(y); ++deg[y];
        }
        BFS();

        printf("%d", ans[0]);
        FOR(i,1,LAST(ans)) printf(" %d", ans[i]);
        puts("");
	}
}
