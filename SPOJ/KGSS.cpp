#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
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

II T[maxN*4];
int ans, ansMax, a[maxN];
int indexMax;

void initTree(int node, int left, int right) {
    if (right < left) return;
    if (left == right) {
    	T[node].F = a[left];
    	T[node].S = left;
    	return;
    }
    int mid = (left + right) / 2;
    initTree(node*2, left, mid);
    initTree(node*2 + 1, mid + 1, right);
    T[node].F = max(T[node*2].F, T[node*2 + 1].F);
    T[node].S = (T[node*2].F > T[node*2 + 1].F) ? T[node*2].S : T[node*2 + 1].S;
}
void update(int node, int left, int right, int index, int val) {
	if (index < left || index > right) return;
	if (left == right && left == index) {
		T[node].F = a[index] = val;
		T[node].S = index;
		return;
	}
	int mid = (left + right) / 2;
	update(node*2, left, mid, index, val);
	update(node*2 + 1, mid+1, right, index, val);
	T[node].F = max(T[node*2].F, T[node*2 + 1].F);
    T[node].S = (T[node*2].F > T[node*2 + 1].F) ? T[node*2].S : T[node*2 + 1].S;
}
void getMax(int node, int left, int right, int i, int j) {
	if (i > right || j < left || j < i) return;
	if (i <= left && right <= j) {
		if (ansMax < T[node].F) {
			ansMax = T[node].F;
			indexMax = T[node].S;
		}
		return;
	}
	int mid = (left + right) / 2;
	getMax(node*2, left, mid, i, j);
	getMax(node*2 + 1, mid+1, right, i, j);
	T[node].F = max(T[node*2].F, T[node*2 + 1].F);
    T[node].S = (T[node*2].F > T[node*2 + 1].F) ? T[node*2].S : T[node*2 + 1].S;
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    int n,m,u,v;
    char type;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    initTree(1,1,n);
	scanf("%d", &m);

	FOR(i,1,m) {
	    scanf("%c", &type);
		scanf("%c %d %d", &type, &u, &v);
		if (type == 'U') update(1,1,n,u,v);
		else {
			ansMax = -1; ans = 0;
			getMax(1,1,n,u,v); ans += ansMax;
			ansMax = -1; int temp = indexMax;
			getMax(1,1,n,u,temp-1);
			getMax(1,1,n,temp+1,v);
			ans += ansMax;
			printf("%d\n", ans);
		}
	}
}
