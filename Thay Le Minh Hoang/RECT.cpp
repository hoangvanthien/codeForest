#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1000002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

LL ans;
int h[maxN], m, n, _left[maxN], _right[maxN];

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
     freopen("rect.inp", "r", stdin);
     freopen("rect.out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i,1,n) scanf("%d", &h[i]);
}

void solve() {
    stack<int> stk;
    FOR(i,1,n) {
        while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
        if (!stk.empty()) _left[i] = stk.top(); else _left[i] = 0;
        stk.push(i);
    }
    stk = stack<int>();
    DFOR(i,n,1) {
        while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
        if (!stk.empty()) _right[i] = stk.top(); else _right[i] = n+1;
        stk.push(i);
    }
    FOR(i,1,n) ans = max(ans, (LL)h[i]*(_right[i]-_left[i]-1));
}

int main() {
	init();
	solve();
	FOR(i,1,n) h[i] = m-h[i];
	solve();
	printf("%lld", ans);
}
