#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x <<endl;
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

using namespace std;
const int N = 13;

int n,m,a[N],pos[N],cnt,trace[N];
vector<int> dsk[N];
vector<II> ans;

void bfs(int s, int t) {
    memset(trace, 0, sizeof trace);
    queue<int> q; q.push(s); trace[s] = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        forit(it, dsk[u]) if (!trace[*it]) {
            trace[*it] = u;
            q.push(*it);
        }
    }
    int j = t;
    while (j != s) {
        ans.pb(mp(j, trace[j]));
        j = trace[j];
    }
    while (!ans.empty()) {
        II pr = ans.back();
        swap(pos[a[pr.F]], pos[a[pr.S]]);
        swap(a[pr.F], a[pr.S]);
        ++cnt;
        ans.pop_back();
    }
}

int main() {
    freopen("input.inp", "r", stdin);
//    freopen("permsort.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%d", &a[i]);
    FOR(i,1,m) {
    	int x,y;
    	scanf("%d%d", &x, &y);
    	dsk[x].pb(y); dsk[y].pb(x);
    }
    FOR(i,1,n) pos[a[i]] = i;
    FOR(k,1,n) {
    	int t = pos[k];
    	if (t == k) continue;
    	bfs(t, k);
    	k = 1;
    }
    printf("%d\n", cnt);
}

