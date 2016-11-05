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
#define uLL unsigned long long
#define LD long double

LL X, Y;

void init() {
    freopen("bricks.inp", "r", stdin);
    freopen("bricks.out", "w", stdout);
    scanf("%lld %lld", &X, &Y);
}

void solve(LD a, LD b, LD c) {
	LD delta = (LD)b*b - 4*(LD)a*c;
	LD sdelta = sqrt(delta);
		LL x1 = (-b+sdelta)/4;
		LL x2 = (-b-sdelta)/4;
		printf("%lld %lld", min(x1+2, x2+2), max(x1+2, x2+2));
}

int main() {
	init();


	solve(2, -(X-4), 2*Y);
}

