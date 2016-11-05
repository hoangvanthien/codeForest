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


const int N = 10002;
const int oo = 1000000007;
int a[N], s[N], f[N], n, m;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("taytruc.inp", "r", stdin);
	freopen("taytruc.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,1,n) s[i] = s[i-1]+a[i];
	DFOR(i,n,1) {
	    int _max = 0;
        FOR(j,1,m) if (i+2*j<=n+1) {
            int _end = min(i+j-1, n);
            int _next = min(i+2*j, n+1);
            maximize(_max, s[_end]-s[i-1]+f[_next]);
        }
        FOR(j,i+1,n) maximize(_max, f[j]);
        f[i] = _max;
	}
	printf("%d\n", f[1]);
}

