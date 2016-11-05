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

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
int m, a[N], f[N];
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	while (T--) {
        scanf("%d", &m);
        if (m==0) {
            cout << 0 << endl;
            continue;
        }
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        int sum = 0;
        FOR(i,1,m) scanf("%d", &a[i]), sum += a[i];
        f[0] = true;
        FOR(i,1,m)
            DFOR(j,sum/2,0)
                if (f[j] && a[i]+j <= sum/2)
                    f[a[i]+j] = true;
        DFOR(j,sum/2,0) if (f[j]) {
            cout << abs(sum-j*2) << endl;
            break;
        }
	}
}

