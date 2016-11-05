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

vector<int> ar;

void init() {
    freopen("turtle.inp", "r", stdin);
    freopen("turtle.out", "w", stdout);
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ar.pb(a); ar.pb(b); ar.pb(c); ar.pb(d);
    sort(ar.begin(), ar.end());
}

int main() {
	init();
	LL ans = 0;
	do {
		if (ar[0] >= ar[2] && ar[3] >= ar[1]) {
			LL temp = (LL)min(ar[0], ar[2]) * min(ar[1], ar[2]);
			ans = max(ans, temp);
		}
	} while (next_permutation(ar.begin(), ar.end()));
	printf("%lld", ans);
}
