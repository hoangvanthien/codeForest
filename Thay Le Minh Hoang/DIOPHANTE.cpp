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

LL a,b,c;

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("diophante.inp", "r", stdin);
    freopen("diophante.out", "w", stdout);
    scanf("%d%d%d", &a, &b, &c);
}

LL gcd(LL x, LL y) {
	x = abs(x); y = abs(y);
	while (y) {
		LL r = x%y; x = y; y = r;
	}
	return x;
}

LL Count(LL l, LL r, LL division, LL module) {
	l -= module; r -= module;
	if (l % division)
		if (l<0) l = -abs(l/division); else l = abs(l/division)+1;
	else l = l/division;
	if (r % division)
		if (r<0) r = -abs(r/division)-1; else r = abs(r/division);
	else r = r/division;
	return (r - l) + 1;
}

void ext_euclid() {
	LL m = a, n = b, xm = 1, xn = 0;
	while (n) {
		LL q = m/n; LL r = m - q*n;
		LL xr = xm - q*xn;
		m = n; xm = xn;
		n = r; xn = xr;
	}
	if (c % m) {
        printf("0");
        exit(0);
	}
	xm *= c/m;
	LL temp = b/m;
	while (xm < 0) xm = xm + temp;
	//LL ym = (m - a * xm)/b;

	LL mod = xm % temp, l = 1, r = (c-b)/a, ans = 0;
	//mod = abs(mod);
	ans = Count(l, r, temp, mod);
	//FOR(i,l,r) if ((i - xm) % temp == mod) ++ans;
	printf("%d", ans);
	// l -= mod; r -= mod;
	// if (r % temp) r = r>=0 ? r/temp*temp : (r/temp-1)*temp;
	// if (l % temp) l = l>=0 ? (l/temp+1)*temp : l/temp*temp;
	// printf("%d", (r-l)/temp+1);
}

int main() {
	init();
	ext_euclid();
}

