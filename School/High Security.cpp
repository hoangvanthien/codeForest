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
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define print(x) FOR(i,1,2) {FOR(j,1,n) cout << x[i][j] << " "; cout << endl; } cout << endl

const int N = 1002;
bool tt[3][N];
int a[3][N], n;

void loang(int x, int y) {
    if (tt[x][y]) return;
    tt[x][y] = true;
    int yy = y;
    while (!tt[x][y-1] && y>1 && !a[x][y-1]) --y, tt[x][y] = true;
    y = yy;
    while (!tt[x][y+1] && y<n && !a[x][y+1]) ++y, tt[x][y] = true;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T;
	scanf("%d", &T);
	FOR(__T,1,T) {
        scanf("%d\n", &n);
        memset(a,0,sizeof a);
        memset(tt,0,sizeof tt);
        FOR(i,1,2) FOR(j,1,n+1) {
            char ch; scanf("%c", &ch);
            if (ch == '\n') continue;
            if (ch == 'X') a[i][j] = 1; else a[i][j] = 0;
        }
//        print(a);
//        print(tt);
        a[1][0] = a[2][0] = a[1][n+1] = a[2][n+1] = 1;
        int ans = 0;
        FOR(i,1,2) FOR(j,1,n) {
            if (!a[i][j] && a[i][j-1] && a[i][j+1] && !tt[i][j]) {
                ++ans;
                tt[i][j] = true;
                if (!a[3-i][j]) loang(3-i, j);
//                print(tt);
            }
        }
        FOR(i,1,2) FOR(j,1,n) if (!a[i][j] && !tt[i][j]) {
            ++ans;
            loang(i,j);
//            print(tt);
        }
        printf("Case #%d: %d\n", __T, ans);
	}

}
