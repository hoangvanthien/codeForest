
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 100002;
LL J;
LL gcd(LL x, LL y) {
    while (y) {
        LL r = x%y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int Case = 0;
	while (scanf("%lld", &J) && J != -1) {
            ++Case;
		char ch; string s;
		cin >> s;
//        db(s);
		LL k = (int)s.size()-2-J;
		LL head = 0, cycle = 0, all = 0;
		DFOR(i, LAST(s), 2)
            all += (LL)round(exp(log(10)*(LAST(s) - i)))*(s[i] - '0');
		head = all/ (LL)round(exp(log(10)*J)); cycle = all % (LL)round(exp(log(10)*J));
		LL a = all - head, b = (LL)round(exp(log(10)*(J+k))) - (LL)round(exp(log(10)*k));
		if (J == 0) a = all, b = (LL)round(exp(log(10)*k));
		LL G = gcd(a,b);
		a /= G; b /= G;

		printf("Case %d: %lld/%lld\n", Case, a, b);
	}
}
