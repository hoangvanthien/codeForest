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


const int N = 1002;
const int oo = 1000000007;
const double pi = acos(-1);
//const LL ooo = (LL)oo*oo;

int dx[] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dy[] = {-2, -1, +1, +2, +2, +1, -1, -2};
int m,n,EXIST;
int a[N][N], f[N][N];
int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
	//	freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	
	while (scanf("%d %d", &m, &n)) {
		if (m == 0 && n == 0) break;
		if ((m == 2 || n == 2)) {
			LL sum = 0;
			sum += ((LL)m*n) / 8;
			sum *= 4;
			if ((m*n) % 8 >= 4) sum += 4; else sum += (m*n) % 8;
			
			printf("%lld knights may be placed on a %d row %d column board.\n", sum, m, n);
			continue;
		}
		if (m == 1 || n == 1) {
			printf("%d knights may be placed on a %d row %d column board.\n", m*n, m, n);
			continue;
		}
		LL sum = 0;
		EXIST = 1;
		LL cntle = n/2;
		if (n % 2 == 1) cntle++;
		FOR(i,1,m) {
			if (i % 2 == 1) sum += cntle;
			else sum += n - cntle;
		}
		
//		db(sum);
		if (2*sum < m*n) {
			sum = m*n - sum;
			EXIST = 0;
		}
//		db(sum);
//		FOR(i,1,m) FOR(j,1,n) if (a[i][j] == EXIST) fill(i,j);
//		FOR(i,1,m) {
//			FOR(j,1,n) printf("%d ", f[i][j]);
//			puts("");
//		}
//		FOR(i,1,m) FOR(j,1,n) if (f[i][j] != 1) sum++;
		printf("%lld knights may be placed on a %d row %d column board.\n", sum, m, n);
	}
}
