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

int n, photo[6][maxN], ans[maxN];

bool cmp(int a, int b) {
    int cnt = 0;
    FOR(i,1,5) if (photo[i][a] < photo[i][b]) ++cnt;
    return (cnt >= 3);
}

void init() {
	freopen("photo.inp", "r", stdin);
	freopen("photo.out", "w", stdout);
    // #ifndef ONLINE_JUDGE
    //     freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
    // #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,1,5) FOR(j,1,n) {
        int x;
        scanf("%d", &x);
        photo[i][x] = j;
    }
    FOR(i,1,n) ans[i] = i;
}

int main() {
	init();
	sort(ans+1, ans+1+n, cmp);
	FOR(i,1,n) printf("%d ", ans[i]);
}

