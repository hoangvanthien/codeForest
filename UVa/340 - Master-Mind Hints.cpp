//
//  340 - Master-Mind Hints.cpp
//  cppGarden
//
//  Created by hoangvanthien on 6/22/16.
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
const double pi = acos(-1);
//const LL ooo = (LL)oo*oo;

int n;
int s[N], g[N];
bool flag_s[N], flag_g[N];

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
	//	freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	int __case = 0;
	while (scanf("%d", &n) && n) {
		printf("Game %d:\n", ++__case);
		FOR(i,1,n) scanf("%d", &s[i]);
		while(true) {
			FOR(i,1,n) scanf("%d", &g[i]);
			if (g[1] == 0) break;
			memset(flag_s, 0, sizeof flag_s);
			memset(flag_g, 0, sizeof flag_g);
			int str = 0, wek = 0;
			FOR(i,1,n) if (s[i] == g[i]) {
				str++;
				flag_s[i] = flag_g[i] = true;
			}
			FOR(i,1,n) if (!flag_s[i])
				FOR(j,1,n) if (!flag_g[j])
					if (s[i] == g[j]) {
						wek++;
						flag_s[i] = flag_g[j] = true;
//						printf("<%d %d>\n", i,j);
						break;
					}
			printf("    (%d,%d)\n", str, wek);
		}
	}
}
