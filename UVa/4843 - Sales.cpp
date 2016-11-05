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
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int ccase; scanf("%d", &ccase);
	while (ccase--) {
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        int ans = 0;
        FOR(i,2,n) FOR(j,1,i-1) ans += a[j] <= a[i];
        printf("%d\n", ans);
	}
}

