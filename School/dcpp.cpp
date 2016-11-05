#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(LL i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(LL i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e18
#define II pair<LL,LL>
#define LL long long
#define vertex pair<LL, II>
#define len S.F
#define index S.S
#define step F
#define show(x) {forit(it, x) cout << (*it).S.S << " "; cout << endl;}

LL n, m, deg[maxN];
LL matchX[maxN], matchY[maxN], trace[maxN];
LL c[maxN][maxN], dj[maxN][maxN], fx[maxN], fy[maxN];
II d[maxN];
LL ans, cost = 0, cnt, k;
LL start, finish;
queue<LL> q;
vector<II> dsk[maxN];
vector<LL> X, Y;

// trace[.] is used to mark the X_node standing before Y_node on the BFS tree
// deg[.] = in degree - out degree
// matchY[.] is used to mark the X_node connecting with Y[.], such that the edge constructed from these 2 nodes
// is admitted edge to the matching

void init() {
   //freopen("input.inp", "r", stdin);
     freopen("dcpp.inp", "r", stdin);
     freopen("dcpp.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    FOR(i,1,n) FOR(j,1,n) {dj[i][j] = (i!=j) ? oo : 0;}
    FOR(i,1,m) {
    	LL u,v,_c;
    	scanf("%lld%lld%lld", &u, &v, &_c);
    	deg[v]++; deg[u]--;
    	dsk[u].pb(mp(v, _c));
    	ans += _c;
    }
}

LL dij(LL s, LL t) {
    if (s == 0 || t == 0) return oo;
	if (dj[s][t] != oo) return dj[s][t];
	set<II > _s;
	_s.clear();
	_s.insert(mp(dj[s][s], s));
	while (!_s.empty())	{
		II top = *(_s.begin());
		LL u = top.S;
		_s.erase(top);
		forit(it, dsk[u]) {
			LL v = (*it).F; LL w = (*it).S;
			if (dj[s][v] > dj[s][u] + w) {
				_s.erase(mp(dj[s][v], v));
				dj[s][v] = dj[s][u] + w;
				_s.insert(mp(dj[s][v], v));
			}
		}
	}
	return dj[s][t];
}

LL getC(LL i, LL j) {
	return c[i][j] - fx[i] - fy[j];
}

void initBipartiteGraph() {
	X.pb(0); Y.pb(0);
	FOR(i,1,n) {
		FOR(j,1,deg[i]) X.pb(i);
		FOR(j,1,-deg[i]) Y.pb(i);
	}
	k = max(X.size(), Y.size());
	FOR(i,1,k-1)
	FOR(j,1,k-1) c[i][j] = dij(X[i], Y[j]);
	--k;
}
void initBFS() {
	// First, the BFS tree only have 'start' node
	q = queue<LL>(); q.push(start);
	memset(trace, 0, sizeof trace);
	FOR(j,1,k) {
		d[j].F = getC(start, j); // So this is the minimum distance from an X_node in BFS tree to y[j]
		d[j].S = start; // define a X_node mentioned above
	}
	finish = 0;
}

// We will run along 0_edge, start with free 0_edge, then discovered 0_edge, ..., finish with a free edge
// Augmenting path starts from a free X_node (start), and finish by a free Y_node
void FindAugmentingPath() { // Find Augmenting Path from X[start] (run along 0_edge)
	do {
		LL i = q.front(); q.pop(); // Get front
		FOR(j,1,k)
            if (trace[j] == 0)
            { // if y[j] is not visited yet
                LL w = getC(i,j); // get weight of edge (x[i], y[j])
                if (w == 0)
                { // if 0_edge
                    trace[j] = i;
                    if (matchY[j] == 0) { // this Y_node is free
                        finish = j;
                        return;
                    }
                    q.push(matchY[j]); // this Y_node is not free, the next edge is admitted, so push matchY[j] into the queue
                }
                if (d[j].F > w) { // update d[j]
                    d[j] = mp(w, i);
                }
            }
	} while (!q.empty());
}

void RollingInTheDeep() {
	// find the minimum weight of the edges which don't belong to BFS tree
	LL delta = oo;
	FOR(j,1,k)
	if (trace[j] == 0) delta = min(delta, d[j].F);
	// Every edge contains X_node which in the BFS tree, will be increase delta
	// In another words, fx[i] += delta, for every i such that x[i] is on BFS tree
	// Oppositely, fy[i] -= delta, for every i such that y[i] is on BFS tree
	fx[start] += delta;
	FOR(j,1,k) if (trace[j]) {
		fy[j] -= delta; fx[matchY[j]] += delta;
	} else {
	    d[j].F -= delta; // decrease the distance from y[j] to BFS tree, as we want the tree to grow
	}

	FOR(j,1,k) if (trace[j] == 0 && d[j].F == 0) {
		trace[j] = d[j].S;
		if (matchY[j] == 0) {finish = j; return;}
		q.push(matchY[j]);
	}
}

void Enlarge() {
	do {
		LL i = trace[finish], next = matchX[i];
		matchX[i] = finish;
		matchY[finish] = i;
		finish = next;
	} while (finish != 0);
}

int main() {
	init();
	initBipartiteGraph();
	FOR(i,1,k) {
		start = i;
		initBFS();
		do {
			FindAugmentingPath();
			if (finish == 0) RollingInTheDeep();
		} while (finish == 0);
		Enlarge();
	}
	FOR(i,1,k) ans += c[i][matchX[i]];
	printf("%lld", ans);
}
