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
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 1002;
const int oo = 1000000007;

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
inline int oppo(int _x) {
    if (_x <= 2) return 3-_x;
    if (_x <= 4) return 7-_x;
    if (_x <= 6) return 11-_x;
}
string face[] = {"", "front", "back", "left", "right", "top", "bottom"};
int n, f[N][N], a[N][N];
II trace[N][N];
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int ccase = 0;
	while (scanf("%d", &n) && n!=0) {
        int hei = 1;
        FOR(i,1,n) FOR(j,1,6) scanf("%d", &a[i][j]);
        memset(f,0,sizeof f);
        memset(trace,0,sizeof trace);
        FOR(j,1,6) f[n][j] = 1;
        DFOR(i,n-1,1) FOR(j,1,6) {
            int op = oppo(j);
            FOR(p,i+1,n) FOR(q,1,6) if (a[p][q] == a[i][op]) {
                if (f[i][j] < f[p][q]) {
                    f[i][j] = f[p][q];
                    trace[i][j] = mp(p, q);
                }
            }
            f[i][j]++; maximize(hei, f[i][j]);
        }
        bool found = 0;
        printf("Case #%d\n%d\n", ++ccase, hei);
        for(int i=1; i<=n && !found; ++i)
            for(int j=1; j<=6 && !found; ++j)
                if (f[i][j] == hei) {
                int x = i, y = j;
                while (x!=0 || y!=0) {
                    printf("%d ", x); cout << face[y] << endl;
                    II temp = trace[x][y];
                    x = temp.F;
                    y = temp.S;
                }
                found = true;
            }
        cout << endl;
	}
}

