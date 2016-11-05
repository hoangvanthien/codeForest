#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
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
#define lb lower_bound
#define ub upper_bound

int x[maxN], g[maxN], r[maxN];
LL sg[maxN], sr[maxN];

bool ok(int i, int j) {
    // sr[i-1] - x[i] <= sr[j] - x[j]
	if (sr[j] - sr[i-1] + x[i] >= x[j]) return true;
	return false;
}

int main() {
//	 freopen("mine.inp", "r", stdin);
//	 freopen("mine.out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int n;
	scanf("%d", &n);
	FOR(i,1,n) scanf("%d%d%d", &x[i], &g[i], &r[i]), sg[i] = sg[i-1] + g[i], sr[i] = sr[i-1] + r[i];
//	deque<int> dq;
//	dq.pb(0);
//	int j = 1;
	LL ans = 0;
	FOR(i,1,n) {
	    DFOR(j,n,i) if (ok(i,j)) {
            ans = max(ans, sg[j] - sg[i-1]);
            break;
	    }
//		while (ok(i, j) && j <= n)
//            dq.pb(j), ++j;
//		if (ok(i, dq.back()))
//			ans = max(ans, sg[dq.back()] - sg[i-1]);
	}
	printf("%lld", ans);
}
