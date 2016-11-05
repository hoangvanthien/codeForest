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
#define ld long double

const int N = 100002;
const int oo = 1000000007;

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
int n, a[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int ccase = 0;
	while (scanf("%d", &n), n) {
        ++ccase;
        printf("Case %d:\n", ccase);
        FOR(i,1,n) scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        int Q, query; scanf("%d", &Q);
        FOR(k,1,Q) {
            scanf("%d", &query);
            int mmin = oo, ans;
            FOR(i,1,n-1) {
                int j=i+1;
                for(; j<=n ; ++j) {
//                    mmin = abs(a[i]+a[j]-query);
                    if (mmin > abs(a[i]+a[j]-query)) {
                        ans = a[i]+a[j];
                        mmin = abs(a[i]+a[j]-query);
                    }
                    if (mmin == 0) break;
                }
            }
            printf("Closest sum to %d is %d.\n", query, ans);
        }
	}
}

