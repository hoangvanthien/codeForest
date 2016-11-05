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

const int N = 105;
int visited[N], ass[N],m,n,t;
vector<int> dsk[N];

bool visit(int u) { // u in X
    if (visited[u] == t) return false; // u has been visited this time
    else visited[u] = t;
    forit(it, dsk[u]) if (ass[*it] == 0 || visit(ass[*it]))
    // *it is in Y. If it's free or we can find an augmenting path from ass[*it] (in X)
    {
        ass[*it] = u; // change match
        return true; // found augmenting path
    }
    return false; // can't found an augmenting path from u
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d %d", &m, &n);
	int x,y;
	while (scanf("%d %d", &x, &y) != EOF) dsk[x].pb(y);
	int cnt = 0;
	FOR(i,1,m) {
        ++t;
        cnt += visit(i);
	}
	printf("%d\n", cnt);
	FOR(i,1,n) if (int v = ass[i]) // v != 0
        printf("%d %d\n", v, i);
}
