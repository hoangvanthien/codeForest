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
int n,m,a[N],v[N];
pair<double, int> r[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,n) {
        scanf("%d%d", &a[i], &v[i]);
        r[i] = {(double)v[i] / a[i], i};
	}
	sort(r+1, r+1+n);
	int ans = 0;
	DFOR(i,n,1) {
	    if (m <= 0) break;
        int ind = r[i].S;
        int q = m / a[ind];
        ans += q * v[ind];
        m %= a[ind];
	}
	printf("%d\n", ans);
}

