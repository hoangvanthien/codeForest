//
//  278 - Chess.cpp
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
const double pi = acos(-1);
//const LL ooo = (LL)oo*oo;

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
		freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	int T,m,n;
	scanf("%d\n", &T);
	while (T--) {
		char ch;
		scanf("%c", &ch);
		if (ch != 'r' && ch != 'Q' && ch != 'K' && ch != 'k') {
			T++;
			continue;
		}
		scanf("%d%d\n", &m, &n);
		switch (ch) {
			case 'r': case 'Q': printf("%d\n", min(m,n)); break;
			case 'K': {
				int t1 = (m-1)/2 + 1, t2 = (n-1)/2 + 1;
				printf("%d\n", t1*t2);
				break;
			}
			case 'k': {
				int cntln = n/2 + (n % 2 == 1), cntlm = m/2 + (m % 2 == 1);
				int sum = cntln*cntlm + (n-cntln) * (m-cntlm);
				if (sum * 2 < m*n) sum = m*n-sum;
				printf("%d\n", sum);
			}
		}
	}
	
}
