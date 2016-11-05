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
int n, D, d[N], cnt[2];

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T;
	scanf("%d", &T);
	while (T--) {
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d", &n, &D);
        int red = 0, remain = n%(D+1), dd = 0;
        if (remain == 0) remain = D+1;
        FOR(i,1,D) {
            scanf("%d", &d[i]);
            cnt[d[i]]++;
            dd = dd ^ d[i];
            if (i == remain) red = cnt[1];
        }
        if (n <= D) {
            if (cnt[1] % 2) puts("1"); else puts("0");
        } else {
            cnt[dd]++;
            red += cnt[1];
            if (red % 2) puts("1"); else puts("0");
        }
	}
    return 0;

}
