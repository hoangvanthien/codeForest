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
int n,k,rao[N];
II a[N];
vector<int> dg;
template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}


LL f(II p1, II p2, II p3) {
    LL a = p2.S-p3.S, b = p3.F-p2.F;
    LL c = p2.F*p3.S - p2.S*p3.F;
    return a*p1.F + b*p1.S + c;
}
bool on(II p1, II p2, II p3) {
    return (p1.F >= min(p2.F, p3.F) && p1.F <= max(p2.F, p3.F) && p1.S >= min(p2.S, p3.S) && p1.S <= max(p2.S, p3.S) && f(p1, p2, p3) == 0);
}
bool khacphia(II p1, II p2, II p3, II p4) {
    return ((f(p1,p3,p4)>0 && f(p2,p3,p4)<0) || (f(p1,p3,p4)<0 && f(p2,p3,p4)>0));
}
bool check(int u) {
    II M = a[u], N = mp(10001, a[u].S);
    int res = 0;
    FOR(i,1,k) {
        if (on(M, a[dg[i]], a[dg[i+1]])) return true;
        if (khacphia(M, N, a[dg[i]], a[dg[i+1]]) && khacphia(a[dg[i]], a[dg[i+1]], M, N)) ++res;
        if (on(a[dg[i+1]], M, N) && khacphia(a[dg[i]], a[dg[i+2]], M, N)) ++res;
        if (on(a[dg[i+1]], M, N) && on(a[dg[i]], M, N) && khacphia(a[dg[i-1]], a[dg[i+2]], M, N)) ++res;
    }
    return res%2;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("raovuon.inp", "r", stdin);
	freopen("raovuon.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &k);
	dg.pb(0);
	FOR(i,1,k) {
	    int x; scanf("%d", &x);
	    dg.pb(x);
	    rao[x] = true;
	}
	dg[0] = dg.back();
	if (dg.size()) {dg.pb(dg[1]);
	dg.pb(dg[2]);}

	FOR(i,1,n) {
        int x,y; scanf("%d%d", &x, &y);
        a[i] = mp(x,y);
	}
	int ans = 0;
    FOR(i,1,n) if (!rao[i])
        ans += !check(i);
    printf("%d", ans);
}
