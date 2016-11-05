#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
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
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;
vector<pair<double, double> >a;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int n,l,w;
	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
        a.clear(); a.pb(mp(0,0));
        FOR(i,1,n) {
            int p,R; scanf("%d%d", &p, &R);
            double d = (double)R*R-(double)w*w/4;
            if (d < 0) {
                a.pb(mp((double)-oo, (double)oo));
                continue;
            }
            a.pb(mp(-sqrt(d)+p,-sqrt(d)-p));
        }
        sort(a.begin()+1, a.end());
        int ans = 0;
        double r = 0;
        for(int i=1; i<=n; ++i)
        if (a[i].F > r && i==1) {
            ans = -1;
            break;
        } else {
            double mmax = r-1;
            while (a[i].F <= r && i <= n) maximize(mmax, -a[i].S), ++i;
            --i;
            ++ans;
            if (mmax > r) r = mmax; else break;
            if (r >= l) break;
        }
        if (r < l) ans = -1;
        printf("%d\n", ans);
	}
}

