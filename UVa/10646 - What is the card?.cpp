//
//  10646 - What is the card?.cpp
//  cppGarden
//
//  Created by hoangvanthien on 6/20/16.
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

int n, T;
string s;
int a[N];
string cards[N];
vector<string> ans;

int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
	//	freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	scanf("%d\n", &T);
	FOR(__test, 1, T) {
		getline(cin, s);
		FOR(i,1,52) cards[i] = "", a[i] = 0;
		FOR(i,0,s.size()-1) if (i % 3 == 0) {
			a[i/3 + 1] = ('2' <= s[i] && s[i] <= '9') ? s[i] - '0' : 10;
			cards[i/3 + 1] += s[i]; cards[i/3 + 1] += s[i+1];
		}
		int Y = 0;
		int i = 52;
		i -= 25;
		FOR(k,1,3) {
			Y += a[i];
			i -= 10 - a[i];
			i--;
			
		}
//		db(i);
		ans.clear();
		FOR(k,1,i) ans.pb(cards[k]);
		FOR(k, 52-24, 52) ans.pb(cards[k]);
		printf("Case %d: ", __test);
		cout << ans[Y-1] << endl;
	}
	
}
