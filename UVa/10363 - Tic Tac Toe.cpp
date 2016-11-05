//
//  10363 - Tic Tac Toe.cpp
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
int a[4][4];
int winX = 0, winO = 0;

bool checkCol(int i) {
	if (a[1][i] == 0) return false;
	for (int j = 1; j <= 3; ++j) if (a[j][i] != a[1][i]) return false;
	if (a[1][i] == 1) winX++;
	else winO++;
	return true;
}

bool checkRow(int i) {
	if (a[i][1] == 0) return false;
	for (int j = 1; j <= 3; ++j) if (a[i][j] != a[i][1]) return false;
	if (a[i][1] == 1) winX++;
	else winO++;
	return true;
}

void checkDiag() {
	if (a[1][1] != 0) {
		bool flag = true;
		for (int i = 1; i <= 3; ++i)
			if (a[i][i] != a[1][1]) {
				flag = false;
				break;
			}
		if (flag) if (a[1][1] == 1) winX++;
		else winO++;
	}
	if (a[1][3] != 0) {
		bool flag = true;
		for (int i = 1; i <= 3; ++i)
			if (a[i][4 - i] != a[1][3]) {
				flag = false;
				break;
			}
		if (flag) if (a[1][3] == 1) winX++;
		else winO++;
	}
}


int main() {
	
#ifndef ONLINE_JUDGE
	freopen("/Users/macbookair/Documents/CodeGarden/cppGarden/INPUT.INP", "r", stdin);
		freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
	scanf("%d\n", &n);
	for (int ccase = 1; ccase <= n; ++ccase) {
		winX = 0;
		winO = 0;
		for (int i = 1; i <= 4; ++i) {
			string s;
			getline(cin, s);
			//					puts(s);
			//					out.flush();
			if (i == 4) continue;
			for (int j = 1; j <= 3; ++j)
				if (s[j-1] == 'X') a[i][j] = 1;
				else if (s[j-1] == 'O') a[i][j] = -1;
				else a[i][j] = 0;
		}
		int cntX = 0, cntO = 0;
		for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 3; ++j) {
				cntX += a[i][j] == 1 ? 1 : 0;
				cntO += a[i][j] == -1 ? 1 : 0;
			}
		if (cntO > cntX || cntX - cntO > 1) puts("no"); else {
			bool c[4], r[4];
			for (int i = 1; i <= 3; ++i) {
				c[i] = checkCol(i);
				r[i] = checkRow(i);
			}
			checkDiag();
			if ((winX > 0 && winO > 0) || (winX >0 && cntX - cntO != 1) || (winO > 0 && cntX != cntO) || (cntX != cntO && cntX != cntO + 1)) puts("no");
			else puts("yes");
//
//			if ((winX > 0 && winO > 0) || (winX > 0 && cntO >= cntX) || (winO > 0 && cntX > cntO) || winX > 1 || winO > 1){
//				
//				puts("no");
//			} else {
//					puts("yes");
//			}
			
		}
//	no: puts("no");
//	yes: puts("yes");
//		if ((winX > 0 && winO > 0) || (winX >0 && cntX - cntO != 1) || (winO > 0 && cntX != cntO) || (cntX != cntO && cntX != cntO + 1)) goto no;
//		else goto yes;
		
	}
	
	
}
