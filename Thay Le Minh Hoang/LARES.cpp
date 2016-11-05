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

int m,n,k;

void init() {
    freopen("lares.inp", "r", stdin);
    freopen("lares.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
}

int main() {
	init();
	int numGroup = min(m/2, n);
	int remain = m+n-numGroup*3;
	if (remain >= k) printf("%d", numGroup);
	else {
		if ((k - remain)%3 == 0) numGroup -= (k-remain)/3;
		else numGroup -= (k-remain)/3 + 1;
		printf("%d", numGroup);
	}
}
