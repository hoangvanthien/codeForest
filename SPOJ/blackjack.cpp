#include <bits/stdc++.h>

using namespace std;

#define maxN 10001
#define mp make_pair
#define fto(i,x,y) for (int i = (x); i < y; ++i)
#define fdto(i,x,y) for (int i = (x); i > y; --i)
#define F first
#define S second
#define ii pair<int,int>

int m,n,a[maxN];
ii f[2*maxN];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    scanf("%d%d",&n,&m);
    fto(i,0,n) scanf("%d",&a[i]);

    fto(i,0,n-1)
    {
        fto(j,i+1,n)
        f[a[i]+a[j]] = mp(i,j);
    }

    int ans = 0;
    fto(x,2,min(m,2*maxN))
    {
        if (f[x] != mp(0,0))
        {
            fto(k,0,n)
            {
                int y=x+a[k];
                if (y <= m && k != f[x].F && k != f[x].S)
                    ans = max(ans, y);
            }
        }
    }

    fto(k,0,n)
    {
    	fdto()
    }

    printf("%d", ans);
}
