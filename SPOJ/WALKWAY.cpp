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
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 1002;
const int oo = 1000000007;
int ind[N], m;
vector<pair<int, double> > dsk[N];
double d[N];
template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d", &m);
	int n = 0;
	FOR(i,1,m) {
	    int x, y, z; scanf("%d%d%d", &x, &y, &z);
	    if (!ind[x]) ind[x] = ++n;
	    if (!ind[y]) ind[y] = ++n;
	    dsk[ind[x]].pb(mp(ind[y], (double)(x+y)*z/2));
	    dsk[ind[y]].pb(mp(ind[x], (double)(x+y)*z/2));
	}
	int st, fi; scanf("%d%d", &st, &fi);
	priority_queue<pair<double, int> > pq; pq.push(mp(0, ind[st]));
	FOR(i,1,n) d[i] = oo;
	d[ind[st]] = 0;
	while (pq.size()) {
        II U = pq.top(); pq.pop(); int u = U.S;
        if (d[u] != -U.F) continue;
        forit(it, dsk[u]) if (d[it->F] > d[u] + it->S) {
            d[it->F] = d[u] + it->S;
            pq.push(mp(-d[it->F], it->F));
        }
	}
	printf("%.2f", d[ind[fi]]*2/100);
}

