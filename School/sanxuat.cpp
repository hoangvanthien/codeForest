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

int n,m,a[maxN][maxN],f[maxN][maxN];

void init()
{
    freopen("sanxuat.inp", "r", stdin);
    freopen("sanxuat.out", "w", stdout);
}

int dp(int i, int w)
{
//    int maxP = 0;
//    FOR(k,1,a[i][0])
//    {
//        int price = a[i][k];
//        if (price < w) maxP = max(maxP, price);
//    }
//    int temp;
//    if (maxP != 0) temp = dp(i+1, w-maxP); else return 0;
//    f[i][w] =
}

void dp()
{
    FOR(i,1,n)
    {
        FOR(j,0,m)
        {
            f[i][j] = -oo;
            FOR(k,1,a[i][0])
            if (j >= a[i][k])
            f[i][j] = max(f[i][j], f[i-1][j-a[i][k]] + a[i][k]);
        }
    }
}

int main()
{
	init();
	int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &m, &n);
        int sum = 0;
        FOR(i,1,n)
        {
            scanf("%d", &a[i][0]);
            int Min = oo;
            FOR(j,1,a[i][0])
            {
                scanf("%d", &a[i][j]);
                Min = min(Min, a[i][j]);
            }
            sum += Min;
        }
        FOR(i,1,n) FOR(j,0,m) f[i][j] = 0;
        dp();
        if (f[n][m] >= sum && f[n][m] <= m) printf("%d\n", f[n][m]); else printf("-1\n");
    }
}
