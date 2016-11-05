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

II a[maxN], b[maxN];
vector<II> remain;
bool tta[maxN], ttb[maxN];
int n;

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("race.inp", "r", stdin);
    freopen("race.out", "w", stdout);
    scanf("%d", &n);
    int x;
    FOR(i,1,n)  {
        scanf("%d", &a[i].F);
        a[i].S = i;
        //a.pb(x);
    }
    FOR(i,1,n) {
        scanf("%d", &b[i].F);
        b[i].S = i;
        //b.pb(mp(x,i));
    }
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
}

int main() {
    init();
    int j = 1;
    stack<int> stk;
    FOR(i,1,n) {
        while (a[i].F > b[j].F && j <= n && !ttb[j]) {
            stk.push(j);
            ++j;
        }
        if (!stk.empty()) {
            printf("%d %d\n", a[i].S, b[stk.top()].S);
            tta[i] = 1;
            ttb[stk.top()] = 1;
            stk.pop();
        }
    }
    j = n;
    FOR(i,1,n)
    if (!tta[i]) {
        while (ttb[j]) --j;
        printf("%d %d\n", a[i].S, b[j].S);
        --j;
    }
}
