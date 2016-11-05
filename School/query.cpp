#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x <<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 30002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

using namespace std;

vector<int> T[4*maxN];
int a[maxN], ans;

void Merge(int n1, int n2, int n3) {
    T[n3].clear();
    int i = 0, j = 0;
    while (i < T[n1].size() && j < T[n2].size()) {
        if (T[n1][i] < T[n2][j]) T[n3].pb(T[n1][i]), ++i;
        else T[n3].pb(T[n2][j]), ++j;
    }
    while (i < T[n1].size()) T[n3].pb(T[n1][i]), ++i;
    while (j < T[n2].size()) T[n3].pb(T[n2][j]), ++j;
}

void initTree(int node, int l, int r) {
	if (l == r) {
		T[node].pb(a[l]);
		return;
	}
	int mid = (l+r)/2;
	initTree(node*2, l, mid);
	initTree(node*2 + 1, mid + 1, r);
	Merge(node*2, node*2+1, node);
}

void getAns(int node, int l, int r, int i, int j, int val) {
	if (i > r || j < l) return;
	if (i <= l && r <= j) {
		ans += T[node].end() - upper_bound(T[node].begin(), T[node].end(), val);
        return;
	}
	int mid = (l+r)/2;
	getAns(node*2, l, mid, i, j, val);
	getAns(node*2 + 1, mid + 1, r, i, j, val);
}

int main() {
    freopen("query.inp", "r", stdin);
    freopen("query.out", "w", stdout);
    int n,m,u,v,x;
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%d", &a[i]);

    	initTree(1,1,n);
    	FOR(i,1,m) {
    		scanf("%d%d%d", &u, &v, &x);
    		ans = 0;
    		getAns(1,1,n,u,v,x);
    		printf("%d\n", ans);
    	}
}
