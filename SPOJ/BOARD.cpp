#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 405
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

set<int> T[maxN][maxN*4], s;
int a[maxN][maxN], n, m;

void initTree(int col, int node, int l, int r) {
	if (l == r) {
		T[col][node].insert(a[l][col]);
		return;
	}
	int mid = (l + r) >> 1;
	initTree(col, node*2, l, mid);
	initTree(col, node*2 + 1, mid + 1, r);
	T[col][node].insert(T[col][node*2].begin(), T[col][node*2].end());
	T[col][node].insert(T[col][node*2+1].begin(), T[col][node*2+1].end());
	// T[col][node] = T[col][node*2] + T[col][node*2+1];
}

int getDiff(int col, int node, int l, int r, int i, int j) {
	if (i > r || j < l) return 0;
	if (i <= l && r <= j) {
		s.insert(T[col][node].begin(), T[col][node].end());
		return T[col][node].size();
	}
	int mid = (l+r) >> 1;
	return getDiff(col, node*2, l, mid, i, j) + getDiff(col, node*2+1, mid+1, r, i, j);
}

int main() {
	 freopen("board.inp", "r", stdin);
	 freopen("board.out", "w", stdout);
//	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	#endif // ONLINE_JUDGE
	scanf("%d%d", &m, &n);
	int ans = 0;
	FOR(i,1,m) FOR(j,1,n) scanf("%d", &a[i][j]);
	FOR(i,1,n) initTree(i,1,1,n);
	FOR(i1,1,m) FOR(i2,i1,m) {
		int j = 1;
		while (j <= n) {
            int cnt = 0; bool ok = false;
            s.clear();
            while (getDiff(j,1,1,m,i1,i2) == i2 - i1 + 1 && j <= n) {
                ++cnt; ok = true;
                if (s.size() == (i2 - i1 + 1)*cnt) ans = max(ans, (i2 - i1 + 1)*cnt);
                else break;
                ++j;
            }
            if (!ok) ++j;
		}
	}
	printf("%d", ans);

}
