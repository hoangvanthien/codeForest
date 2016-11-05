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
LL a[N], s[N], p;

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T,n; scanf("%d", &T);
	FOR(__T,1,T) {
        scanf("%d %lld", &n, &p);
        FOR(i,1,n) scanf("%lld", &a[i]), s[i] = s[i-1] + a[i];
        LL ans = 0;
        FOR(i,1,n) {
            int pos = upper_bound(s+i, s+n+1, s[i-1]+p) - s - 1;
            if (pos >= i) ans += pos - i + 1;
        }
        printf("Case #%d: %lld\n", __T, ans);
	}
}
