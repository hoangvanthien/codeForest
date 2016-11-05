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

int n, k;
pair<LL, int> a[maxN];

void init() {
   freopen("seq.inp", "r", stdin);
   freopen("seq.out", "w", stdout);
//    freopen("input.inp", "r", stdin);
    scanf("%d%d", &n, &k);
    FOR(i,1,n) scanf("%lld", &a[i].F), a[i].S = i;
    sort(a+1, a+1+n);
}

int main() {
	init();
	FOR(i,1,n) {
		int pos = lower_bound(a+1, a+1+n, mp(a[i].F + k, 0)) - a;
		if (a[pos].F == a[i].F + k && pos != n+1 && pos != i) {
			printf("%d %d", a[pos].S, a[i].S);
			exit(0);
		}
	}
	printf("0 0");
}
