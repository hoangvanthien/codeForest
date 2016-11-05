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

LL gcd(LL a, LL b) {
    a = abs(a); b = abs(b);
    while (a*b != 0) {
        if (a >= b) a %= b; else b%=a;
    }
    return a+b;
}

void init() {
    freopen("intsle.inp", "r", stdin);
    freopen("intsle.out", "w", stdout);
//    freopen("input.inp", "r", stdin);
}

void solve(LL a, LL b, LL c) {
    if (a == 0) {
        if (b == 0)
            if (c == 0) puts("INFINITE"); else puts("NO SOLUTION");
        else if (c % b == 0) puts("INFINITE"); else puts("NO SOLUTION");
    } else
    if (b == 0) {
        if (a == 0)
            if (c == 0) puts("INFINITE"); else puts("NO SOLUTION");
        else if (c % a == 0) puts("INFINITE"); else puts("NO SOLUTION");
    } else
    if (c % gcd(a,b) == 0) puts("INFINITE"); else puts("NO SOLUTION");
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	while (T--) {
        LL a1, a2, b1, b2, c1, c2;
		scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2);
        if (a1 == a2 && b1 == b2 && c1 == c2) { solve(a1, b1, c1); continue; }
        if (a1 == 0 && b1 == 0 && c1 == 0) {solve(a2, b2, c2); continue; }
        if (a2 == 0 && b2 == 0 && c2 == 0) {solve(a1,b1,c1); continue;}
            LL d = a1*b2 - a2*b1;
            LL dx = c1*b2 - c2*b1;
            LL dy = a1*c2 - a2*c1;
            if (d == 0) {
                if (dx == 0 && dy == 0) solve(a1, b1, c1);//printf("INFINITE\n");
                else printf("NO SOLUTION\n");
            } else {
                if (dx%d == 0 && dy%d == 0) printf("%lld %lld\n", dx/d, dy/d);
                else printf("NO SOLUTION\n");
            }
	}
}
