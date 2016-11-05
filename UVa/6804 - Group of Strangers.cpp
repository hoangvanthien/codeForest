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

const int N = 5005;
const int oo = 1000000007;

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}

vector<int> dsk[N];
int c[N][N];
vector<II> ed;
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	FOR(ccase, 1, T) {
        int n, m; scanf("%d%d", &n, &m);
        FOR(i,1,n) dsk[i].clear();
        ed.clear();
        memset(c,0,sizeof c);
        FOR(i,1,m) {
            int x,y; scanf("%d%d", &x, &y);
            dsk[x].pb(y);
            dsk[y].pb(x);
            c[x][y] = c[y][x] = 1;
            ed.pb(mp(x,y));
        }
        LL ans = 0;
        FOR(u,1,n) {
            int cnt_ed = 0;
            forit(it, ed) {
                if (!c[u][it->F] && !c[u][it->S]) cnt_ed++;
            }
            LL cnt_ve = n - dsk[u].size() - 1;
            LL cnt_pair = cnt_ve * (cnt_ve - 1) / 2;
            LL cnt_0ed = cnt_pair - cnt_ed;
            ans += cnt_0ed;
        }
        ans /= 3;
        printf("Case #%d: %lld\n", ccase, ans);
	}
}
