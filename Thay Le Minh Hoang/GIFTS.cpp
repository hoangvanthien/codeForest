#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1000002
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

int a[maxN], nv[maxN], n, m, x;
bool pack[maxN], gift[maxN];

int main() {
	freopen("gifts.inp", "r", stdin);
	freopen("gifts.out", "w", stdout);
	ios::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
	// freopen("input.inp", "r", stdin);
	// #endif // ONLINE_JUDGE

	cin >> m;
	FOR(i,1,m) {
		int x; cin >> x;
		gift[x] = true;
	}
	cin >> n;
	FOR(i,1,n) cin >> a[i];
	int ans = 0;
	FOR(i,1,n) {
		int cnt = 0;
		while (cnt < a[i] && nv[a[i]] + a[i] < maxN) {
			nv[a[i]] += a[i];
			if (gift[nv[a[i]]] && !pack[nv[a[i]]]) ++ans;
			if (!pack[nv[a[i]]]) {
				pack[nv[a[i]]] = true;
				++cnt;
			}
		}
	}
	cout << ans;
}
