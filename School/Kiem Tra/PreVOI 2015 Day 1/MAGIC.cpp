#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 2016
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e18
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound

LL a[maxN][maxN], m, n, gt[2][2], mask[2][2], tt[maxN][maxN];

LL getMin(LL x, LL y) {
	return max(a[x-1][y], a[x][y-1]);
}

LL getMax(LL x, LL y) {
    LL t1 = tt[x+1][y], t2 = tt[x][y+1];
    if (t1 == 0) t1 = oo; else t1 = a[x+1][y];
    if (t2 == 0) t2 = oo; else t2 = a[x][y+1];
	return min(t1, t2);
}

void EXIT() {
    puts("-1");
    exit(0);
}

bool check(LL x, LL y) {
	if (mask[x%2][y%2] == -1) {
        mask[x%2][y%2] = a[x][y] % 2;
        LL &temp = mask[1 - x%2][1 - y%2];
        if (temp == -1) temp = 1 - mask[x%2][y%2];
        else
            if (temp != 1 - mask[x%2][y%2]) return false;
	}
	else if (mask[x%2][y%2] == a[x][y] % 2) return true; else return false;
	return true;
}

LL solve(){
	LL res = 0;
	FOR(i,1,m) FOR(j,1,n)
	if (!tt[i][j]) { // need to be edited`
		a[i][j] = getMin(i,j) + 1;
		if (a[i][j] % 2 != gt[i%2][j%2]) a[i][j]++;
		if (a[i][j] >= getMax(i,j)) return oo;
		res += a[i][j];
	} else {
	    if (a[i][j] <= getMin(i,j) || a[i][j] >= getMax(i, j)) return oo;
	    res += a[i][j];
	}
	return res;
}

int main() {
	freopen("magic.inp", "r", stdin);
	freopen("magic.out", "w", stdout);
	 // #ifndef ONLINE_JUDGE
	 // freopen("input.inp", "r", stdin);
	 // #endif // ONLINE_JUDGE
	FOR(i,0,1) FOR(j,0,1) mask[i][j] = -1;

	scanf("%lld %lld", &m, &n);
	if (m == 1) {
        LL ans = 0;
        FOR(i,1,n) {
            scanf("%lld", &a[m][i]);
            if (a[m][i] != 0)
                if (a[m][i] > a[m][i-1]) ans += a[m][i]; else EXIT();
            else a[m][i] = a[m][i-1]+1, ans += a[m][i];
        }
        printf("%lld", ans);
        return 0;
	}
	if (n == 1) {
        LL ans = 0;
        FOR(i,1,m) {
            scanf("%lld", &a[n][i]);
            if (a[n][i] != 0)
                if (a[n][i] > a[n][i-1]) ans += a[n][i]; else EXIT();
            else a[n][i] = a[n][i-1]+1, ans += a[n][i];
        }
        printf("%lld", ans);
        return 0;
	}

	FOR(i,1,m) FOR(j,1,n) scanf("%lld", &a[i][j]), tt[i][j] = a[i][j];
	FOR(i,1,m) a[i][n+1] = oo; FOR(j,1,n) a[m+1][j] = oo;
	FOR(i,1,m) FOR(j,1,n) if (a[i][j] != 0) {
	    if (!check(i,j)) EXIT();
//	    if ()
	}
	LL ans = oo;
	FOR(i,0,1) FOR(j,0,1) {
		gt[1][1] = (mask[1][1] != -1) ? mask[1][1] : i;
		gt[0][0] = 1 - gt[1][1];
		gt[1][0] = (mask[1][0] != -1) ? mask[1][0] : j;
		gt[0][1] = 1 - gt[1][0];
		ans = min(ans, solve());
	}
	if (ans != oo) printf("%lld", ans); else EXIT();
}
