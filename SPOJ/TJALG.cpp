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
int num[N], low[N], cnt, ans, n, m;
vector<int> dsk[N];
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    st.push(u);
    forit(it, dsk[u]) {
        int v = *it;
        if (num[v] != 0) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        ++ans;
        int v;
        do {
            v = st.top(); st.pop();
            num[v] = low[v] = oo;
        } while (v!=u);
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
        int x,y;
        scanf("%d%d", &x, &y);
        dsk[x].pb(y);
	}
	FOR(i,1,n) if (num[i] == 0) dfs(i);
	printf("%d\n", ans);
}
