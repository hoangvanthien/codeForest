#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n;
string s1[maxN], s2[maxN];
map<string, int> m1, m2;

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
}

int main() {
	init();
	scanf("%d", &n);
	getline(cin, s1[0]);
	FOR(i,1,n) { getline(cin, s1[i]); m1[s1[i]]++; }
	FOR(i,1,n) { getline(cin, s2[i]); m2[s2[i]]++; }
	int ans = 0;
	forit(it, m1) ans += min(it->S, m2[it->F]);
//	int ans = min(m1["correct"], m2["correct"]) + min(m1["wronganswer"], m2["wronganswer"]) + min(m1["timelimit"], m2["timelimit"]);
//	FOR(i,1,n) {
//        if (s1[i] == "correct" && s2[i] == "timelimit") ans += 2; else
//            if (s2[i] == "correct" && s1[i] == "timelimit") ans += 2; else
//            if (s1[i] == s2[i]) ans += 1;
//	}
	printf("%d", ans);
}

