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
const double pi = acos(-1);
const LL ooo = (LL)oo*oo;

int f[55][55], a[55];

int cost(int i, int j) {
    if (j-i == 1) return 0;
    if (j-i == 2) return a[j] - a[i];
    if (f[i][j]) return f[i][j];
    int res = oo;
    FOR(k,i+1,j-1) minimize(res, cost(i, k) + cost(k, j));
    res += a[j] - a[i];
    return f[i][j] = res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int n, l;
	while (scanf("%d", &l) && l) {
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        a[n+1] = l;
        memset(f, 0, sizeof f);
        printf("The minimum cutting is %d.\n", cost(0, n+1));
	}
}

