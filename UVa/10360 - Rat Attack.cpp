// Find maximal rectangle
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
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 1025;
const int oo = 1000000007;
int a[N+1][N+1], f[N+1][N+1], m=0,n=0;
int getSum(int x, int y, int u, int v) {
    x = max(x,1); y = max(y,1); u = max(u,1); v = max(v,1);
    x = min(x,m); y = min(y,n); u = min(u,m); v = min(v,n);
    return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}
inline bool valid(int x, int y) {
    return (1<=x && x<=m && 1<=y && y<=n);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
    int T; scanf("%d", &T);
    while (T--) {
        int d,q; scanf("%d%d", &d, &q);
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        m=n=0;
        FOR(i,1,q) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            a[x+1][y+1] = z;
            m = max(m,x+1); n = max(n,y+1);
        }
        FOR(i,1,m) {
            int sumrow = 0;
            FOR(j,1,n) {
                sumrow += a[i][j];
                f[i][j] = f[i-1][j] + sumrow;
            }
        }
        int ans = 0; II p;
        FOR(i,1,m) FOR(j,1,n) {
            int s = getSum(i-d,j-d,i+d,j+d);
            if (ans < s) ans = s, p = mp(i,j);
        }
        printf("%d %d %d\n", p.F-1, p.S-1, ans);
    }
}

