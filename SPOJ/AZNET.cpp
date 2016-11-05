#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
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

vector<pair<II, int> > Edge;
int n,m,T,a[maxN], b[maxN], pSet[maxN], numSet[maxN], depthSet[maxN];
bool tt[maxN];

void init() {
    // freopen("AZNET.inp", "r", stdin);
    // freopen("AZNET.out", "w", stdout);
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &T);
}
void initSet() {
	//pSet.resize(n+1);
	FOR(i,1,n) {
		depthSet[i] = 0;
		numSet[i] = 1;
		pSet[i] = i;
	}
}
int findSet(int u) {
	return (pSet[u] == u ? u : pSet[u] = findSet(pSet[u]));
}
void unionSet(int root1, int root2) {
	if (depthSet[root1] > depthSet[root2]) {
		pSet[root2] = root1;
//		numSet[root1] += numSet[root2];
	} else {
		pSet[root1] = root2;
//		numSet[root2] += numSet[root1];
		if (depthSet[root1] == depthSet[root2]) depthSet[root2]++;
	}
}
bool isSameSet(int u, int v) {
	return (findSet(u) == findSet(v));
}
bool AttempAdd(II e) {
    int r1 = findSet(e.F), r2 = findSet(e.S);
    if (r1 == r2) return 0;
    unionSet(r1, r2);
    return 1;
}
int main() {
	init();
	while (T--) {
        memset(tt, 0, sizeof tt);
		scanf("%d%d", &n, &m);
		FOR(i,1,n-1) scanf("%d", &a[i]);
		FOR(i,1,n-1) scanf("%d", &b[i]);
		Edge.clear();
		FOR(i,1,m) {
			int u,v,c;
			scanf("%d%d%d", &u, &v, &c);
//			if (c == 1) typeA.pb(mp(u,v)); else typeB.pb(mp(u,v));
            Edge.pb(mp(mp(u,v), c));
		}
        int A = 0, B = 0;
        initSet();
		forit(it, Edge)
		if ((*it).S == 1) A += AttempAdd((*it).F);

		initSet();
		forit(it, Edge)
        if ((*it).S == 2) B += AttempAdd((*it).F);
        // Here, no need to initialize new tree because we should add more A edges after find x
        // Now find x
        int Min = 2*oo, x;
		FOR(k, max(0, n-1-B), min(n-1, A))
		if (Min >= a[k] + b[n-1-k]) {
			x = k;
			Min = a[k] + b[n-1-k];
		}
		// Put all A edge into tree without any condition, together with marking these edges
		FOR(i,0,m-1) {
            if (Edge[i].S == 1) {
                tt[i+1] = AttempAdd(Edge[i].F);
            }
		}

		// Make new tree
		initSet();
        int cnt = 0;
        // Put all the A edges which is marked into the new tree
        FOR(i,0,m-1) {
            if (tt[i+1]) cnt += AttempAdd(Edge[i].F);
        }
        // Put the unmarked A edges into the tree and mark them
        FOR(i,0,m-1) {
            // If the quantity of A edges was enough
            if (cnt == x) break;
            if (Edge[i].S == 1 && !tt[i+1]) {
                tt[i+1] = AttempAdd(Edge[i].F);
                cnt += tt[i+1];
            }
        }
        // Put the B edges into the tree
        FOR(i,0,m-1) {
            // If the spanning tree was constructed successfully
            if (cnt == n-1) break;
            if (Edge[i].S == 2) {
                tt[i+1] = AttempAdd(Edge[i].F);
                cnt += tt[i+1];
            }
        }
        FOR(i,1,m) if (tt[i]) printf("%d ", i);
//
		printf("\n");
	}
}
