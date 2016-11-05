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
#define MOD 1000000007
#define II pair<int,int>
#define LL long long

LL a,b,something;

// answer = a*q + q*(1+2+...+a)*b for q = 1...<b
// x = k.b + q
// 1 <= k/q <= a
// 1 <= q < b

void init()
{
    freopen("sodep.inp", "r", stdin);
    freopen("sodep.out", "w", stdout);
    scanf("%lld%lld", &a, &b);
    LL sum1a;
    sum1a = a*(a+1)/2;
    sum1a %= MOD;
    something = (sum1a*b)  % MOD;
    //db(something);
}

int main()
{
	init();
	LL ans = 0;
	for (LL q = 1; q<b; ++q)
	{
		int temp = (a*q) % MOD;
		temp += (something*q)%MOD;
		ans += temp%MOD; ans %= MOD;
	}
	printf("%d\n", ans);
}
