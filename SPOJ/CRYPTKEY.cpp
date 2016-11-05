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

const int N = 100002;
LL a[N],k;
int n;

LL gcd(LL a, LL b) {
	while (b) {
		LL r = a % b;
		a = b;
		b = r;
	}
	return a;
}

LL lcm(LL a, LL b) {
	return a/gcd(a,b)*b;
}

bool isGCD() {
	LL t = 0;
	FOR(i,1,n) if (a[i] % k == 0) {
		if (t == 0) t = a[i]/k;
		else t = gcd(t, a[i]/k);
		if (t == 1) break;
	}
	return t==1;
}

bool isLCM() {
	LL t = 0;
	FOR(i,1,n) if (k % a[i] == 0) {
		if (t == 0) t = k/a[i];
		else t = gcd(t, k/a[i]);
		if (t == 1) break;
	}
	return t==1;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		FOR(i,1,n) scanf("%lld", &a[i]);
//		FOR(i,1,1000) {
//            k = i;
//            if (isGCD() || isLCM()) printf("%d ", i);
//        }
//        printf("\n");
		scanf("%lld", &k);
		bool ans = isGCD() || isLCM();
		if (ans) puts("YES"); else puts("NO");
	}
}
