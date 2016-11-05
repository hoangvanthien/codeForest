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

const int N = 2002;
map<double, int> val[N];
int cnt[N];
II point[N];

double getLeng(II p1, II p2) {
    return sqrt((p2.F - p1.F)*(p2.F - p1.F) + (p2.S - p1.S)*(p2.S - p1.S));
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T, n;
	scanf("%d", &T);
	FOR(__T, 1, T) {
        scanf("%d", &n);
        FOR(i,1,n) {
            scanf("%d %d", &point[i].F, &point[i].S);
            val[i].clear();
        }
        memset(cnt, 0, sizeof cnt);
        FOR(i,1,n-1) FOR(j,i+1,n) {
            double t = getLeng(point[i], point[j]);
            int t1 = val[i][t]++; cnt[i] += t1;
            int t2 = val[j][t]++; cnt[j] += t2;
        }
        LL ans = 0;
        FOR(i,1,n) ans += cnt[i];
        printf("Case #%d: %lld\n", __T, ans);
	}
}
