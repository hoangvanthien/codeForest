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
#define II pair<long long,long long>
#define LL long long



void init() {
//     #ifndef ONLINE_JUDGE
//         freopen("input.inp", "r", stdin);
//     #endif // ONLINE_JUDGE
   freopen("cwater.inp", "r", stdin);
   freopen("cwater.out", "w", stdout);
}

LL gcd(LL x, LL y) {
	x = abs(x); y = abs(y);
	while (x*y!=0) {
		if (x>=y) x%=y; else y%=x;
	}
	return x+y;
}

void solve(LL a, LL b, LL c) {
	II pa = mp(1,0);
	II pb = mp(0,1);
	LL d = gcd(a,b);
	LL m = a, n = b;
	while (n) {
		LL q = m/n;
		LL r = m-q*n;
		II pr = mp(pa.F - pb.F*q, pa.S - pb.S*q);
		m = n; pa = pb;
		n = r; pb = pr;
	}
    if (c%d || c == 0) {
        printf("-1\n");
        return;
    }
	pa.F *= c/d; pa.S *= c/d;
//	if (abs(pa.F % (b/d)) < abs((pa.F + b/d) % (b/d))) pa.F = pa.F % (b/d); else pa.F = (pa.F + b/d) % (b/d);
//	if (abs(pa.S % (a/d)) < abs((pa.S + a/d) % (a/d))) pa.S = pa.S % (a/d); else pa.S = (pa.S + a/d) % (a/d);
//    pa.F = min(abs(pa.F) % (b/d), abs(b/d - abs(pa.F) % (b/d)));
//    pa.S = min(abs(pa.S) % (a/d), abs(a/d - abs(pa.S) % (a/d)));
    LL _k = (pa.S - pa.F)/(b/d + a/d);
    LL ans = oo;
    FOR(k,_k-2,_k+2) {
//        if ((pa.F + k*b/d) > 0  && (pa.S - k*a/d) < 0 && abs(pa.F + k*b/d) < abs(pa.S - k*a/d)) continue;
//        if ((pa.F + k*b/d) < 0  && (pa.S - k*a/d) > 0 && abs(pa.F + k*b/d) > abs(pa.S - k*a/d)) continue;

        ans = min(ans, abs(pa.F + k*b/d) + abs(pa.S - k*a/d));
    }
	if (ans != oo) printf("%lld\n", ans);
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	while (T--) {
		LL a,b,c;
		scanf("%lld %lld %lld", &a, &b, &c);
		solve(a,b,c);
	}
}
