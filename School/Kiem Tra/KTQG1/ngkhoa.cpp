#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define pb push_back
#define maxN 102

int n,m,a[maxN][maxN],t,hs[maxN];
bool th[maxN];

void init()
{
    freopen("ngkhoa.inp", "r", stdin);
    freopen("ngkhoa.out", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &m);
    t = 0;
    FOR(i,0,m)
    {
        scanf("%d", &a[i+1][0]);
        FOR(j,1,a[i+1][0]+1)
        {
            scanf("%d", &a[i+1][j]);
            if (a[i+1][j] == 1)
            {
                t++;
                th[i+1] = true;
            }
        }
    }
}

int main()
{
    init();
    if (t==0)
    {
        printf("%d", 1);
        exit(0);
    }
    int dem = 0;
    FOR(i,1,m+1)
    {
        if (th[i])
        FOR(j,1,a[i][0]+1)
        {
//            if (hs[a[i][j]] < dem)
                hs[a[i][j]]++;
        }
        else
            {
                int Max = 0;
                FOR(j,1,a[i][0]+1) Max = max(Max,hs[a[i][j]]);
                FOR(j,1,a[i][0]+1) hs[a[i][j]] = Max ;
            }
    }

    FOR(i,1,n+1)
    if (hs[i] == t) printf("%d\n", i);
}
