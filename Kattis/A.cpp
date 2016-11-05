#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n, speed[maxN], hour[maxN];

void init() {

}

int main() {
	init();
	while (scanf("%d", &n) && n!=-1) {
        FOR(i,1,n) scanf("%d%d", &speed[i], &hour[i]);
        int ans = 0;
        FOR(i,1,n) ans += speed[i] * (hour[i] - hour[i-1]);
        printf("%d miles\n", ans);
	}
}
