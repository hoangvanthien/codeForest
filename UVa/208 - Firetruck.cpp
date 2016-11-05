//
//  208 - Firetruck.cpp
//  cppGarden
//
//  Created by hoangvanthien on 6/21/16.
//  Copyright © 2016 Marclix. All rights reserved.
//

#include <stdio.h>
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

const int N = 100002;
const int oo = 1000000007;

int trace[N], fi, n;
bool tt[N], flag[N];
vector<int> dsk[N];
int cnt;

void print(int k) {
	if (k == 0) return;
	print(trace[k]);
	if (k != fi) printf("%d ", k); else printf("%d\n", k);
}

void attemp(int u) {
//	if (i == 0) {
		if (u == fi) {
//			FOR(i,1,n) printf("%d ", trace[i]);
//			puts("");
			print(fi);
			++cnt;
			return;
		}
//	}
	forit(it, dsk[u]) if (!tt[*it] && flag[*it]) {
		tt[*it] = true;
		trace[*it] = u;
		attemp(*it);
		tt[*it] = false;
	}
}

void bfs() {
	flag[fi] = true;
	queue<int> q;
	q.push(fi);
	while (q.size()) {
		int u = q.front(); q.pop();
		forit(it, dsk[u]) if (!flag[*it]) {
			flag[*it] = true;
			q.push(*it);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	 freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	int __case = 0;
	while (scanf("%d", &fi) != EOF) {
		printf("CASE %d:\n", ++__case);
		 FOR(i,1,N-1) dsk[i].clear();
		cnt = 0;
		n = 0;
		int x,y;
		while (scanf("%d%d", &x, &y) && x && y) {
			if (x == 0 && y == 0) break;
			dsk[x].pb(y); dsk[y].pb(x);
			maximize(n, max(x,y));
		}
		FOR(i,1,n) sort(dsk[i].begin(), dsk[i].end());
		memset(flag, 0, sizeof flag);
		bfs();
			memset(tt, 0, sizeof tt);
			tt[1] = true;
			attemp(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, fi);
	}
}