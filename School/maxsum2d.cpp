#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 1001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int m,n,a[maxN][maxN];
int sum[maxN][maxN];

void init()
{
    freopen("maxsum2d.inp", "r", stdin);
    freopen("maxsum2d.out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i,1,m+1)
    {
        FOR(j,1,n+1)
        {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i-1][j] + a[i][j];
        }
    }
}

void print()
{
    FOR(i,1,m+1)
    {
        FOR(j,1,n+1) printf("%d ", sum[i][j]);
        printf("\n");
    }
}

int main()
{
	init();
	int ans = -oo;
    FOR(i1,1,m+1)
    FOR(i2,i1,m+1)
    {
        int s = 0;
        FOR(k,1,n+1)
        {
            s += sum[i2][k] - sum[i1-1][k];
            ans = max(ans, s);
            s = max(s, 0);
        }
    }

    //print();
    printf("%d", ans);
}
