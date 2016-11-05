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
#define AR(x) FOR(i,1,m) {FOR(j,1,n) if (x[i][j] != -oo) cout << x[i][j] << " "; else cout << "- "; cout << endl;}

const int N = 1005;
const LL oo = LONG_LONG_MAX;
LL _f[N][N], g1[N][N], g2[N][N], g3[N][N], g4[N][N], a[N][N], sum, Max;
int m,n,r,w,h;

inline LL max(LL x1, LL x2, LL x3, LL x4) {return max(max(max(x3, x4), x2), x1);}
//inline void maximize(LL &x, LL y) { x = max(x,y); }
//void minimize(LL &x, LL y) { x = min(x,y); }
inline LL getSum(int x, int y, int u, int v) {
    if (!(1<=x && x<=m && 1<=y && y<=n && 1<=u && u<=m && 1<=v && v<=n)) return -oo;
    return _f[u][v] - _f[u][y-1] - _f[x-1][v] + _f[x-1][y-1];
}

inline bool check(int x, int y) {
    return (x+r <= m && 1 <= x-r && y+r <=n && 1 <= y-r);
}

inline LL _g1(int x, int y) {if (1 <= x && x <= m && 1 <= y && y <= n) return g1[x][y]; else return -oo;}
inline LL _g2(int x, int y) {if (1 <= x && x <= m && 1 <= y && y <= n) return g2[x][y]; else return -oo;}
inline LL _g3(int x, int y) {if (1 <= x && x <= m && 1 <= y && y <= n) return g3[x][y]; else return -oo;}
inline LL _g4(int x, int y) {if (1 <= x && x <= m && 1 <= y && y <= n) return g4[x][y]; else return -oo;}
void get(int x, int y) {
    sum = 0; Max = -oo;
    int j = 0;
    DFOR(i,r,0) {
        sum += getSum(x-i, y+j, x+i, y+j);
        if (j!=0) sum += getSum(x-i, y-j, x+i, y-j);
        if (j!=0) Max = max(Max, max(_g1(x-i-1, y-j), _g2(x-i-1, y+j), _g3(x+i+1, y+j), _g4(x+i+1, y-j)));
        ++j;
    }
//    printf("%d %d %lld\n", x, y, sum);
//    int i = -1;
//    maximize(Max, max(g1[x-i-h][y-j-w+1], g2[x-i-h][y+j], g3[x+i+1][y+j], g4[x+i+1][y-j-w+1]));
    Max = max(Max, max(_g1(x-r-1, n), _g2(x-r-1, 1), _g3(x+r+1, 1), _g4(x+r+1, n)));
    Max = max(Max, max(_g1(m, y-r-1), _g2(m, y+r+1), _g3(1, y+r+1), _g4(1, y-r-1)));
//    maximize(Max, max(g2[x-h+1][y+j], g3[x][y+j]));
//    maximize(Max, max(g1[x-h+1][y-j-w+1], g4[x][y-j-w+1]));
}
//void cal(int i, int j) {
////    if (!(1 <= i && i <= m && 1 <= j && j <= n)) {f[i][j] = -oo; return;}
//    if (!(1 <= i+h-1 && i+h-1 <= m && 1 <= j+w-1 && j+w-1 <= n)) {f[i][j] = -oo; return;}
//    f[i][j] = getSum(i, j, i+h-1, j+w-1);
//}
void init() {
    ios::sync_with_stdio(0);
//    scanf("%d%d%d%d%d", &m, &n, &h, &w, &r);
    cin >> m >> n >> h >> w >> r;
//    FOR(i,0,N+1) FOR(j,0,N+1) g1[i][j] = g2[i][j] = g3[i][j] = g4[i][j] = -oo;
    FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
    FOR(i,1,m) {
        LL sumrow = 0;
        FOR(j,1,n) sumrow += a[i][j], _f[i][j] = _f[i-1][j] + sumrow;
    }
//    FOR(i,1,m) FOR(j,1,n) cal(i, j);
//    FOR(i,1,m) g1[i][0] = g2[i][0] = g3[i][0] = g4[i][0] = g1[i][n+1] = g2[i][n+1] = g3[i][n+1] = g4[i][n+1] = -oo;
//    FOR(j,1,n) g1[0][j] = g2[0][j] = g3[0][j] = g4[0][j] = g1[m+1][j] = g2[m+1][j] = g3[m+1][j] = g4[m+1][j] = -oo;
}
void buildG() {
    FOR(i,1,m) {
        LL maxrow1 = -oo;
        FOR(j,1,n) {
            maxrow1 = max(maxrow1, getSum(i-h+1, j-w+1, i, j));
            if (i > 1) g1[i][j] = max(maxrow1, g1[i-1][j]); else g1[i][j] = maxrow1;
        }
    }
    FOR(i,1,m) {
        LL maxrow2 = -oo;
        DFOR(j,n,1) {
            maxrow2 = max(maxrow2, getSum(i-h+1, j, i, j+w-1));
            if (i > 1) g2[i][j] = max(maxrow2, g2[i-1][j]); else g2[i][j] = maxrow2;
        }
    }
    DFOR(i,m,1) {
        LL maxrow1 = -oo;
        DFOR(j,n,1) {
            maxrow1 = max(maxrow1, getSum(i, j, i+h-1, j+w-1));
            if (i < m) g3[i][j] = max(maxrow1, g3[i+1][j]); else g3[i][j] = maxrow1;
        }
    }
    DFOR(i,m,1) {
        LL maxrow2 = -oo;
        FOR(j,1,n) {
            maxrow2 = max(maxrow2, getSum(i, j-w+1, i+h-1, j));
            if (i < m) g4[i][j] = max(maxrow2, g4[i+1][j]); else g4[i][j] = maxrow2;
        }
    }
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
    init();
//    db(-oo);
    buildG();
//    AR(g1);
//    puts("");
//    AR(g2);
//    puts("");
//    AR(g3);
//    puts("");
//    AR(g4);
//    puts("");
    LL ans = -oo;
    FOR(i,1,m) FOR(j,1,n) if (check(i,j)) {
        get(i, j);
        if (Max != -oo) ans = max(ans, sum+Max);
//        maximize(ans, Sum+_max);
    }
    if (ans != -oo) cout << ans; else cout <<"no solution";
}
