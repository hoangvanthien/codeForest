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

const int N = 100002;
const int oo = 1000000007;
int n,m,dr[N],kn[N];

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	while (scanf("%d%d", &n, &m) && !(n==0 && m==0)) {
        int ans = 0;
        FOR(i,1,n) cin >> dr[i];
        FOR(j,1,m) cin >> kn[j];
        sort(dr+1, dr+n+1); sort(kn+1, kn+m+1);
        int j = 1;
        FOR(i,1,n) {
            while (kn[j] < dr[i] && j <= m) ++j;
            if (j > m) {ans = oo; break;}
            ans += kn[j]; ++j;
        }
        if (ans == oo) puts("Loowater is doomed!");
        else printf("%d\n", ans);
	}
}

