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
    freopen("maxsum1d.inp", "r", stdin);
    freopen("maxsum1d.out", "w", stdout);
    scanf("%d", &n);
    Min[0] = oo;
    FOR(i,1,n+1)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
        Min[i] = min(Min[i-1], (LL)sum[i]);
    }
    LL ans = -oo;
    FOR(i,1,n+1) ans = max(ans, sum[i] - Min[i]);
    printf("%d", ans);
}
