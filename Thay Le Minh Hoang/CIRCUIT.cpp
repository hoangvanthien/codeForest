#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
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

vector<II> dsk[maxN];
vector<int> ans;
//map<II, int> order;
bool tt[maxN];
int n, m;
II trace[maxN];

void dfs(int u) {
	tt[u] = true;
	forit(it, dsk[u]) {
		if (tt[(*it).F]) {
			puts("YES");
			printf("%d ", (*it).S);
			int v = u;
			while (v != (*it).F) {
				ans.pb(trace[v].S);
				v = trace[v].F;
			}
			forrit(rit, ans) printf("%d ", *rit);
			exit(0);
		}
		else {
			trace[(*it).F] = mp(u, (*it).S);
			dfs((*it).F);
		}
	}
}

void init() {
	freopen("circuit.inp", "r", stdin);
	freopen("circuit.out", "w", stdout);
//    #ifndef ONLINE_JUDGE
//    freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    FOR(i,1,m) {
    	int u,v; scanf("%d%d", &u, &v);
    	dsk[u].pb(mp(v,i));
    	// order[mp(u,v)] = i;
    }
}

int main() {
	init();
	FOR(i,1,n) if (!tt[i]) dfs(i);
	puts("NO");
}
