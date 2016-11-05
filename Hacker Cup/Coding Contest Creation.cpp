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
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 100002;
bool ok[N];
int n, ans, a[N];
int solve(int i, int pos) {
    ok[i]=1;
    if (pos==4) return 0;
    if (i==n) {
        return 4-pos;
    }
    if (a[i] >= a[i+1]) return 4-pos;
    int res = 0, ins = (a[i+1]-a[i]-1)/10;
    if (ins+pos >= 4) return 4-pos;
    res += ins;
    res += solve(i+1, ins+pos+1);
    return res;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	FOR(__T,1,T) {
	    memset(ok,0,sizeof ok);
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        ans = 0;
        FOR(i,1,n) if (!ok[i]){
            ans += solve(i,1);
        }
        printf("Case #%d: %d\n", __T, ans);
	}
}
