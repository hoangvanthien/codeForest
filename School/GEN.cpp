#include <bits/stdc++.h>
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


const int N = 1002;
const int oo = 1000000007;
const double EPS = 1e-9;
vector<int> a,b;
stringstream ss, ss2;
int f[N][N];
map<unsigned LL, int> val;
bool isprime(unsigned LL x) {
    FOR(i,2,sqrt(x)) if (x%i == 0) return false;
    return true;
}

bool ok(unsigned LL x) {
    unsigned LL sq = (unsigned LL)(sqrtl(x));
    if (sq*sq == x) return true;
    double t = exp(log(x)/3 + EPS);
    unsigned LL temp = (unsigned LL)(t);

    if (temp*temp*temp != x) return false;
    return isprime(temp);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("gen.inp", "r", stdin);
	freopen("gen.out", "w", stdout);
	#endif // ONLINE_JUDGE
	string s;
	unsigned LL x;
	int cnt = 0;
	a.pb(0); b.pb(0);
	getline(cin, s);
	ss.str(s);
	while (ss >> x) if (ok(x)){
        a.pb(x);
	}
	getline(cin, s);
    ss2.str(s);
	while (ss2 >> x) if (ok(x)) {
        b.pb(x);
	}
    int m = a.size()-1, n = b.size()-1;

    FOR(i,1,m) FOR(j,1,n) if (a[i] == b[j]) f[i][j] = f[i-1][j-1]+1;
    else f[i][j] = max(f[i][j-1], f[i-1][j]);

    cout << f[m][n] << endl;

}

