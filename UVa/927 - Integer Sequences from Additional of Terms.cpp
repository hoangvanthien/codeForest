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
LL f[N],m;
LL power(LL a, LL e) {
    LL ans = 1;
    FOR(i,1,e) ans*=a;
    return ans;
}
LL getf(int n) {
    LL ans = 0;
    FOR(i,0,m)
        ans += f[i]*power(n,i);
    return ans;
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int ccase; scanf("%d\n", &ccase);
	while (ccase--) {
//        string s; getline(cin, s);
//        stringstream ss; ss.str(s);
        int temp;
        scanf("%d", &m);
        FOR(i,0,m) scanf("%d", &f[i]);
        int d,k; scanf("%d%d", &d, &k);
        int i = 1; LL cur = 0;
        while (1) {
//            LL temp = getf(i);
            if (cur + i*d >= (LL)k) {
                LL temp = getf(i);
                printf("%lld\n", temp);
                break;
            }
            cur += i*d;
            ++i;
        }
	}
}

