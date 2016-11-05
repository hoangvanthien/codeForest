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

const int N = 25;
const int oo = 1000000007;
int f[210][N];
vector<int> ds[N];
int dp(int w, int i) {
    if (w<0) return -1;
    if (i==0) return 0;
    if (f[w][i]) return f[w][i];
    int res = -1;
    forit(it, ds[i]) {
        int temp = dp(w- *it, i-1);
        if (temp != -1) res = max(res, *it + temp);
    }
    f[w][i] = res;
    return res;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T; cin >> T;
	while (T--) {
        int m,c; cin >> m >> c;
        memset(f, 0, sizeof f);
        FOR(i,1,c) ds[i].clear();
        FOR(i,1,c) {
            int x; cin >> x;
            FOR(j,1,x) {
                int y; cin >> y;
                ds[i].pb(y);
            }
        }
        int ans = dp(m,c);
        if (ans == -1) puts("no solution");
        else printf("%d\n", ans);
	}
}
