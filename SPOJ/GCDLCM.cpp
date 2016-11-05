// I have done this shit for days
// Submitted 23 times. ==...
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1000005
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<LL,LL>
#define LL long long
#define lb lower_bound
#define ub upper_bound

const LL mod = 1000000009;
int X[maxN], Y[maxN], nextDivisor[maxN];
int m,n,k;
map<int, LL> val;

void initera() {
    LL t = (LL) sqrt(maxN);
	FOR(i,2,t) if (nextDivisor[i] == 0) {
        for(LL j = i*i; j < maxN; j+=i)
            if (nextDivisor[j] == 0) nextDivisor[j] = i;
	}
}

void putX(int x) {
	while (nextDivisor[x] && x % nextDivisor[x] == 0) {
        X[nextDivisor[x]]++;
        x /= nextDivisor[x];
	}
	if (x > 1) X[x]++;
}

void putY(int y) {
	while (nextDivisor[y] && y % nextDivisor[y] == 0) {
        Y[nextDivisor[y]]++;
        y /= nextDivisor[y];
	}
	if (y > 1) Y[y]++;
}

LL powerMod(int base, int exponent) {
	if (exponent == 0) return 1;
	LL t = powerMod(base, exponent/2), T = (t*t) % mod;
	if (exponent % 2 == 0) return T;
	return (T*base) % mod;
}

LL power(int base) {
    if (base == 0) return 0;
    LL &_val = val[base];
    if (_val != 0) return _val;
    return _val = powerMod(base, k);
}

int main() {
	freopen("gcdlcm.inp", "r", stdin);
	freopen("gcdlcm.out", "w", stdout);
	 // #ifndef ONLINE_JUDGE
	 // freopen("input.inp", "r", stdin);
	 // #endif // ONLINE_JUDGE
	initera();
//	db(era.back());
	scanf("%d %d %d", &m, &n, &k);

	FOR(i,1,m) {int x; scanf("%d", &x); putX(x);}
	FOR(j,1,n) {int y; scanf("%d", &y); putY(y);}
	LL ans = 1;
	FOR(i,2,maxN-1)
        if (Y[i] != X[i]) {
            if (Y[i] < X[i]) {ans = 0; break;}
            int temp = Y[i] - X[i] + 1;
            LL t = (power(temp) - power(temp-1)*2 + 2*mod + power(temp-2))%mod;
            ans = (ans*t) % mod;
        }

	printf("%lld", ans);
}
