#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x <<endl;
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
#define DD(x) d[x.first][x.second]
#define FF(x) f[x.first][x.second]
#define TT(x) tt[x.first][x.second]

using namespace std;
const int N = 505;

int m,n,a[N][N],f[N][N],ans;
II s,fin;
vector<II> bomb;
queue<II> q;

void buildF() {


	    while (!q.empty()) {
            II pr = q.front();
            q.pop();
            FOR(x,-1,1) FOR(y,-1,1) if (abs(x) + abs(y) == 1) {
                int xx = pr.F + x, yy = pr.S + y;
                if (xx < 1 || yy < 1 || xx > m || yy > n) continue;
                if (f[xx][yy] == -1) {
                    f[xx][yy] = f[pr.F][pr.S] + 1;
                    q.push(mp(xx, yy));
                }
            }
	    }

}

void dij() {
    // now we find path
    ans = oo;
	priority_queue<pair<int, II> > pq;
	pq.push(mp(FF(s), s));
	FF(s) = -1;
	while (!pq.empty()) {
		pair<int, II> t = pq.top();
		pq.pop();
		ans = min(ans, t.F);
		if (t.S == fin) break;
		FOR(i,-1,1) FOR(j,-1,1) if (abs(i) + abs(j) == 1) {
			II coor = mp(t.S.F + i, t.S.S + j);
			if (coor.F < 1 || coor.S < 1 || coor.F > m || coor.S > n) continue;
			if (FF(coor) != -1) {
				pq.push(mp(FF(coor), coor));
				FF(coor) = -1;
			}
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d%d\n", &m, &n);
    FOR(i,1,m) FOR(j,1,n+1) {
        char ch;
        if (scanf("%c", &ch) == EOF) break;
        if (ch == '.') a[i][j] = 0; else
        if (ch == '+') a[i][j] = 1; else
        if (ch == 'V') a[i][j] = 3; else
        if (ch == 'J') a[i][j] = 4; else continue;
        f[i][j] = -1;
    	if (a[i][j] == 3) s = mp(i, j);
    	if (a[i][j] == 4) fin = mp(i, j);
    	if (a[i][j] == 1) f[i][j] = 0, q.push(mp(i,j));
    }
    buildF();
//    FOR(i,1,m) {
//        FOR(j,1,n) cout << f[i][j] << " ";
//        cout << endl;
//    }
    dij();
    printf("%d", ans);
}
