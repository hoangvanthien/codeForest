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
int bank[] = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000};
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	while (T--) {
        LL n; scanf("%I64d", &n);
        LL ans = 0;
        FOR(i,0,8) {
            LL q = n / bank[i];
            ans += q;
            n %= bank[i];
        }
        if (n != 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
	}
}

