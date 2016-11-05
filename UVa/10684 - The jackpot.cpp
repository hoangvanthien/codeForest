#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 1000002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN],n;
LL sum[maxN], Min[maxN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif
    while (true)
    {
        scanf("%d", &n);
        if (n==0) break;
        Min[0] = oo;
        FOR(i,1,n+1)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
            Min[i] = min(Min[i-1], (LL)sum[i]);
        }
        LL ans = -oo;
        FOR(i,1,n+1) ans = max(ans, sum[i] - Min[i]);
        if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
        else printf("Losing streak.\n");
    }
}
