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
int sum[maxN][maxN],dt,T,K;

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
    scanf("%d", &T);
    FOR(___i, 0, T)
    {
        scanf("%d%d%d", &m, &n, &K);
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
        int ans = -oo, dt = -oo;
        FOR(i1,1,m+1)
        FOR(i2,i1,m+1)
        {
            int s = 0;
            int width = 0, index = 1;
            FOR(j,1,n+1)
            {
                int k = j-1;
                s = 0;
                while (s<=K && k<n)
                {
                    k++;
                    s += sum[i2][k] - sum[i1-1][k];
                }
                if (s>K)
                {
                    s -= sum[i2][k] - sum[i1-1][k];
                    k--;
                }
                width = k-j+1;
                if (dt < (i2-i1+1) * (width))
                {
                    ans = s;
                    dt = (i2-i1+1) * (width);
                }
                else
                    if (dt == (i2-i1+1) * (width) && s < ans)
                    ans = s;
//                width++;
//                if (s<K)
//                {
//
//                    if (dt < (i2-i1+1) * (width))
//                    {
//                        ans = s;
//                        dt = (i2-i1+1) * (width);
//                    }
//                    else
//                        if (dt == (i2-i1+1) * (width) && s < ans)
//                        ans = s;
//                }
//                else
//                {
//                    s -= sum[i2][index] - sum[i1-1][index];
//                    index++;
//                    width --;
//                }

            }
        }
        printf("Case #%d: %d %d\n", ___i+1, dt, ans);

    }
}
