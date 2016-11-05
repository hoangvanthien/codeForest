#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 50002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

II T[maxN*4];
int ansMax;

void lazy_update(int node) {
	if (T[node].S != 0) {
		int &memo = T[node].S;
		T[node*2].F += memo;
		T[node*2+1].F += memo;
		T[node*2].S += memo;
		T[node*2+1].S += memo;
		memo = 0;
	}
}

void update(int node, int left, int right, int i, int j, int val) {
	if (i > right || j < left) return;
	if (i <= left && right <= j) {
		T[node].F += val;
		T[node].S += val;
		return;
	}
	int mid = (left + right) / 2;
	lazy_update(node);
	update(node*2, left, mid, i, j, val);
	update(node*2+1, mid+1, right, i, j, val);
	T[node].F = max(T[node*2].F, T[node*2+1].F);
}

void getMax(int node, int left, int right, int i, int j) {
	if (i > right || j < left) return;
	if (i <= left && right <= j) {
		ansMax = max(ansMax, T[node].F);
		return;
	}
	int mid = (left + right) / 2;
	lazy_update(node);
	getMax(node*2, left, mid, i, j);
	getMax(node*2+1, mid+1, right, i, j);
}

void init() {
    #ifndef ONLINE_JUDGE
        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
}

int main() {
	init();
	int u,v,n,m,k;
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
		scanf("%d%d%d", &u, &v, &k);
		update(1,1,n,u,v,k);
	}
	scanf("%d", &m);
	FOR(i,1,m) {
		scanf("%d%d", &u, &v);
		ansMax = 0;
		getMax(1,1,n,u,v);
		printf("%d\n", ansMax);
	}
}

