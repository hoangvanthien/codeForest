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
#define x first
#define y second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 9;
const int oo = 1000000007;
int n;
double f[1<<(N*2)], d[N*2][N*2];
II p[N*2];
double dp(int status) {
    if (status == (1 << (2*n)) - 1) return 0;
    if (f[status]) return f[status];
    double res = oo;
    FOR(i,0,2*n-1) if (!(status & (1<<i)))
        FOR(j,i+1,2*n-1) if (!(status & (1<<j))) {
            res = min(res, (double)d[i][j]+dp(status|(1<<i)|(1<<j)));
        }
    return f[status] = res;
}
double dist(II A, II B) {
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
    	freopen("input.inp", "r", stdin);
    	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
    int ccase = 0;
	while (scanf("%d\n", &n) && n!=0) {
        ++ccase;
        FOR(i,0,2*n-1) {
            string s; cin >> s;
            int x,y; scanf("%d%d", &x, &y);
            p[i] = mp(x,y);
        }
        FOR(i,0,2*n-1) FOR(j,0,2*n-1) d[i][j] = dist(p[i], p[j]);
        memset(f, 0,sizeof f);
        double w = dp(0);
        printf("Case %d: %.2f\n", ccase, w);
	}
}

