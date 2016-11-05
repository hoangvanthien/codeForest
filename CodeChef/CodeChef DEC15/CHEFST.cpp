#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

inline LL sumUp(LL t) {
    return t*(t+1)/2;
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while (T--) {
    	LL n1, n2, m, n;
    	scanf("%lld %lld %lld", &n1, &n2, &m);
    	n = min(n1, n2);
    	m = min(m, n);
    	while (m > 0 && n > 0) {
            LL t1 = sumUp(m);
            LL l = 1, r = m, ans;
            while (l <= r) {
                LL mid = (l+r)/2, temp = sumUp(mid-1);
                if (t1 - temp <= n) {
                    r = mid-1;
                    ans = mid;
                } else l = mid+1;
            }
            n -= t1 - sumUp(ans-1);
            m = ans - 1;
//            for (int i = 1; i <= m; ++i) {
//                LL temp = sumUp(i-1);
//                if (t1 - temp <= n) {
//                    n -= t1-temp;
//                    m = i-1;
//                    break;
//                }
//            }
            m = min(m, n);
    	}
    	printf("%lld\n", 2*n + abs(n2-n1));
    }
}

