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
int c[N][N], n, m, gr;
vector<II> ed;
const int mem = 30;
void add(int x, int y) {
    int gr_y = y/mem;
    c[x][gr_y] |= 1 << (y%mem);
}
int bitCount(int __x) {
    bitset<30> mask = __x;
    return mask.count();
}
int siz[N];
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	FOR(ccase, 1, T) {
        scanf("%d%d", &n, &m);
        gr = n/mem;
        if (n%mem) gr++;
        FOR(i,0,n-2) siz[i] = 30;
        siz[n-1] = n%mem;
        FOR(i,0,n-1) dsk[i].clear();
        ed.clear();
        memset(c,0,sizeof c);
        FOR(i,1,m) {
            int x,y; scanf("%d%d", &x, &y);
            --x; --y;
            add(x,y);
            add(y,x);
            ed.pb(mp(x,y));
        }
        LL ans = 0;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        forit(it, ed) {

            int x = it->F, y = it->S;

            FOR(u,0,gr-1) {
                cnt1 -= bitCount(c[x][u] | c[y][u]);
                cnt2 += bitCount(c[x][u] ^ c[y][u]);
                cnt3 += bitCount(c[x][u] & c[y][u]);
            }
            cnt1 += n;
            cnt2 -= 2;
        }
        ans = (LL)n*(n-1)*(n-2)/6 - cnt1 - cnt2/2 - cnt3/3;
        printf("Case #%d: %lld\n", ccase, ans);
	}
}
