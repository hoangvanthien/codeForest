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
#define uLL unsigned long long

unsigned LL a,b,k,ans;
string cycle, not_cyc;
vector<string> cyc;
map<unsigned LL, int> surplus;

void init() {
    freopen("digit.inp", "r", stdin);
    freopen("digit.out", "w", stdout);
//    #ifndef ONLINE_JUDGE
//        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    scanf("%llu %llu %llu", &a, &b, &k);
}

uLL multi(uLL x, uLL y) {
    if (y == 1) return x%b;
    uLL temp = multi(x, y/2);
    if (y % 2 == 0) {
        return (temp*2)%b;
    } else {
        return ((temp*2)%b + x%b) %b;
    }
}

uLL power(uLL base, uLL exponent) {
    if (exponent == 0) {
        return 1;
    }
    uLL temp = power(base, exponent/2);
    if (exponent % 2 == 0) {
        return multi(temp, temp);
    } else {
        return (multi(temp, temp)*base)%b;
    }
}

int main() {
	init();
    printf("%llu", multi(a, power(10, k-1))*10/b);
}
