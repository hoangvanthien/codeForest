
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

string cmd;
const LL MOD = oo;
LL p3[maxN];

LL powerMod(int exponent) {
	if (p3[exponent] != 0) return p3[exponent];
	LL temp = powerMod(exponent/2);
	if (exponent % 2) return p3[exponent] = (temp*temp*3)%MOD;
	else return p3[exponent] = (temp*temp)%MOD;
}

void init() {
	freopen("treewalk.inp", "r", stdin);
	freopen("treewalk.out", "w", stdout);
    // #ifndef ONLINE_JUDGE
    //     freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
    // #endif // ONLINE_JUDGE
    getline(cin, cmd);
    p3[0] = 1;
}

int main() {
	init();
	int cnt = 0;
	LL ans = 1;
	FOR(i,0,(int)cmd.length()-1) {
		if (cmd[i] == 'P') continue;
		if (cmd[i] != '*') {
			ans *= 2; ans %= MOD;
			if (cmd[i] == 'L') ;
			if (cmd[i] == 'R') ans += powerMod(cnt), ans %= MOD;
		} else {
			ans = (5*ans)%MOD + powerMod(cnt); ans %= MOD;
			++cnt;
		}
	}
	printf("%lld\n", ans);
}
