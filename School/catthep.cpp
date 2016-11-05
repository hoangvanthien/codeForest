#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 1002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int len, n, a[maxN], c[maxN][maxN], f[maxN][maxN];

void init()
{
    freopen("catthep.inp", "r", stdin);
    freopen("catthep.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &len, &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    sort(a+1,a+1+n);
    a[n+1] = len;
    FOR(i,0,n+1)
    FOR(j,0,n+1) c[i][j] = abs(a[i]-a[j]);

}

int dp(int l, int r)
{
    if (r-l <= 1) return 0;
    if (f[l][r] != 0) return f[l][r];
    int res = oo;
    //res = oo;
    FOR(i,l+1,r-1)
    {
        int t1 = dp(l, i);
        int t2 = dp(i, r);
        res = min(res, c[l][r] + t1 + t2);
    }
//    return f[l][r] = c[l][r] + m1 + m2;
    return f[l][r] = res;
}

int main()
{
	init();
	printf("%d", dp(0,n+1));
}
