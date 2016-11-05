#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 10000002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

LL n,k,a[maxN],left1[maxN],left2[maxN], right1[maxN], right2[maxN] ;
stack<LL> stk1, stk2;

void init() {
    freopen("WEIGHT.inp", "r", stdin);
    freopen("WEIGHT.out", "w", stdout);
    scanf("%lld", &n);
    FOR(i,1,n) scanf("%lld", &a[i]);
}
int main() {
    init();
    FOR(i,1,n) {
        while (!stk1.empty() && a[stk1.top()] > a[i]) stk1.pop();
        if (stk1.empty()) left1[i] = 0; else left1[i] = stk1.top();
        stk1.push(i);

        while (!stk2.empty() && a[stk2.top()] < a[i]) stk2.pop();
        if (stk2.empty()) left2[i] = 0; else left2[i] = stk2.top();
        stk2.push(i);
    }
    stk1 = stk2 = stack<LL>();
    DFOR(i,n,1) {
        while (!stk1.empty() && a[stk1.top()] >= a[i]) stk1.pop();
        if (stk1.empty()) right1[i] = n+1; else right1[i] = stk1.top();
        stk1.push(i);

        while (!stk2.empty() && a[stk2.top()] <= a[i]) stk2.pop();
        if (stk2.empty()) right2[i] = n+1; else right2[i] = stk2.top();
        stk2.push(i);
    }
    LL ans = 0;
    FOR(i,1,n) ans += a[i]*(i - left2[i])*(right2[i] - i) - a[i]*(i - left1[i])*(right1[i] - i);
    printf("%lld", ans);
}
