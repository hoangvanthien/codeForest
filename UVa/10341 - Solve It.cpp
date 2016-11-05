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
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 100002;
const int oo = 1000000007;
int p,q,r,s,t,u;
double f(double x) {
    return exp(-x)*p + sin(x)*q + cos(x)*r + tan(x)*s + x*x*t + u;
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	while (scanf("%d%d%d%d%d%d", &p,&q,&r,&s,&t,&u) != EOF) {
        if (f(0) * f(1) > 0) puts("No solution");
        else {
            double l = 0, r = 1;
            while (l+1e-7 <= r) {
                double mid = (l+r)/2;
                if (f(l)*f(mid) <= 0) r = mid; else l=mid;
            }
            printf("%.4f\n", (l+r)/2);
        }
	}
}

