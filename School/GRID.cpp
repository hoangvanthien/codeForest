
#include <bits/stdc++.h>
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


const int N = 52;
const int oo = 1000000007;
char c[N][N];
int main() {
	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int m,n; scanf("%d%d", &m, &n);
	char ch;
//	cin >> ch;
	int xmin = m, xmax = 1, ymin = n, ymax = 1;
	FOR(i,1,m) FOR(j,1,n) {
        cin >> ch;
        if (j==n+1) continue;
        if (ch == '*') minimize(xmin, i), minimize(ymin, j), maximize(xmax, i), maximize(ymax, j);
	}
	FOR(i,1,m) {
        FOR(j,1,n) if (xmin <= i && i <= xmax && ymin <= j && j <= ymax) {
            cout << '*';
        } else cout << '.';
        cout << endl;
	}

}
