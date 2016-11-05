#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define x first
#define y second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;
int orientation(II A, II B, II C) {
    II va = mp(B.x - A.x, B.y - A.y);
    II vb = mp(C.x - B.x, C.y - B.y);
    int temp = va.x * vb.y - vb.x * va.y;
    if (temp > 0) return -1; // counterclockwise
    if (temp < 0) return 1; // clockwise
    return 0; // collinear
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d", &n);
	FOR(i,1,n) {
        scanf("%d%d", &p[i].x, &p[i].y);
	}
	int cnt = 0;
	FOR(i,1,n) {
        int next = (i+1)%n + 1, later = (i+2)%n + 1;
        cnt += orientation(p[i], p[next], p[later]) > 0;
	}
	if (cnt == n || cnt == 0) puts("This is Convex Polygon");
	else puts("This is not Convex Polygon");
}

