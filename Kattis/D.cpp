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

int T, D, M, leng[maxN], start[maxN];

int firstDay(int index) {
    if (index == 1) return 0;
    return (start[index-1] + leng[index-1])%7;
}

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	while (T--) {
        scanf("%d %d", &D, &M);
        FOR(i,1,M) scanf("%d", &leng[i]);
        int ans = 0;
        FOR(i,1,M) {
            start[i] = firstDay(i);
            if (start[i] == 0 && leng[i] >= 13) ans += 1;
        }
        printf("%d\n", ans);
	}
}

