#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
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

int n,q,k,a[maxN];

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d %d", &n, &q);
	FOR(i,1,n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	while (q--) {
		string type;
		getline(cin, type);
		cin >> type;
		if (type == "FIND") {
			scanf("%d", &k);
			printf("%d\n", a[n-k+1]);
		} else {
			scanf("%d", &k);
			FOR(i,1,n) a[i] = a[i] ^ k;
			sort(a+1, a+1+n);
		}
	}
}
