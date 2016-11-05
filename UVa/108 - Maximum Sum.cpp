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
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
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
	while (scanf("%d", &n) != EOF)
    {
        m = n;
        FOR(i,1,n+1)
        FOR(j,1,n+1)
        {
            a[i][j] = 0;
            sum[i][j] = 0;
        }
        FOR(i,1,m+1)
        {
            FOR(j,1,n+1)
            {
                scanf("%d", &a[i][j]);
                sum[i][j] = sum[i-1][j] + a[i][j];
            }
        }
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
        printf("%d\n", ans);
    }
}
