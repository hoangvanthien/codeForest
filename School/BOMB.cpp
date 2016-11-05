#include "bits/stdc++.h"
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
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))
#define duyet FOR(i,1,n) FOR(j,1,n)
#define db2d(x) cout << #x << endl; FOR(i,1,n) {FOR(j,1,n) cout << x[i][j] << " "; cout << endl;}

const int N = 10;
const int oo = 1000000007;
const double pi = acos(-1);
//const LL ooo = (LL)oo*oo;
int dx[] = {0, -1, -1, 0, +1, +1, +1, 0, -1, -2, 0, +2, 0};
int dy[] = {0, 0, +1, +1, +1, 0, -1, -1, -1, 0, +2, 0, -2};

int n;
int a[N][N], f[N][N], f2[N][N];
vector<II> v[14];

bool valid(int x, int y) {return 1<=x && x<=n && 1<=y && y<=n;}

bool check() {
	duyet if(a[i][j] < 0) {
		return false;
	}
	return true;
}
bool done() {
	duyet if (a[i][j] != 0) return false;
	return true;
}
void attemp(int x, int y) {
//	db2d(f);
	if (x == 9) {
		if (1) {
			db2d(f);
			exit(0);
		} else return;
	}
//	if (!valid(x,y)) return;
	
	f[x][y] = 1;
	FOR(i,0,12) if (valid(x+dx[i], y+dy[i])) a[x+dx[i]][y+dy[i]]--;
	if (check()) {
		if (y+1 <= n) attemp(x, y+1);
		else attemp(x+1, 1);
	}
	f[x][y] = 0;
	FOR(i,0,12) if (valid(x+dx[i], y+dy[i])) a[x+dx[i]][y+dy[i]]++;
	if (y+1 <= n) attemp(x, y+1);
	else attemp(x+1, 1);
}

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
	//	freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	n = 8;
	FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
	FOR(i,1,n) FOR(j,1,n) f[i][j] = -1;
	attemp(1,1);
	db2d(f);
}
