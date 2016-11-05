#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
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

int n,m,cnt,f[maxN];
bool visit[maxN];
vector<int> pset;

int findSet(int i) {
    return (pset[i] == i ? i : pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) {
    return (findSet(i) == findSet(j));
}

void unionSet(int i, int j) {
    pset[findSet(i)] = findSet(j);
}

void init() {
    freopen("friend.inp", "r", stdin);
    freopen("friend.out", "w", stdout);
    scanf("%d%d", &n, &m);
    pset.pb(0);
    FOR(i,1,n) pset.pb(i);
    FOR(i,1,m)
    {
    	int u,v;
    	scanf("%d%d", &u, &v);
    	unionSet(u,v);
    }
}

int main() {
	init();
	int ans = 0;
	FOR(i,1,n) f[findSet(i)]++;
	printf("%d\n", *max_element(f+1, f+1+n));
}
