#include <bits/stdc++.h>
using namespace std;

#define oo 1e18
#define FOR(i,x,y) for(int i= (x); i<(y); ++i)
#define maxN 1001
#define ll long long

struct
{
    int x,y,u,v;
} k[maxN*maxN];

int m,n,_k, ar[maxN][maxN];
ll sum[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("MINCUT.INP", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &m, &n, &_k);
    ll _sum = 0;
    FOR(i,0,m)
    {
        _sum = 0;
        FOR(j,0,n)
        {
            scanf("%d",&ar[i+1][j+1]);
            _sum += ar[i+1][j+1];
            sum[i+1][j+1] = _sum + sum[i][j+1];
        }
    }
    FOR(i,0,_k)
    {
        scanf("%d%d%d%d", &k[i].x, &k[i].y, &k[i].u, &k[i].v);
    }
}

inline ll GetSum(int _x, int _y, int _u, int _v)
{
    if (_u<_x || _v<_y) return 0;
    return sum[_u][_v] - sum[_x-1][_v] - sum[_u][_y-1] + sum[_x-1][_y-1];
}

inline void print(ll value)
{
    printf("%d\n", value);
}

void implement(int _x, int _y, int _u, int _v)
{
    int l = _x - 1, r = _u, pos;
    while (l<=r)
    {
        int mid = (l+r)/2;
        ll s1 = GetSum(_x,_y,mid,_v), s2 = GetSum(mid+1,_y,_u,_v);
        if (s1<=s2)
        {
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    ll ans1 = abs(GetSum(_x,_y,pos,_v) - GetSum(pos+1,_y,_u,_v));
    pos ++;
    if (pos <= _u) ans1 = min(ans1, abs(GetSum(_x,_y,pos,_v) - GetSum(pos+1,_y,_u,_v)));
    ////
    l = _y - 1;
    r = _v;
    while (l<=r)
    {
        int mid = (l+r)/2;
        ll s1 = GetSum(_x,_y,_u,mid), s2 = GetSum(_x,mid+1,_u,_v);
        if (s1<=s2)
        {
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    ll ans2 = abs(GetSum(_x,_y,_u,pos) - GetSum(_x,pos+1,_u,_v));
    pos ++;
    if (pos<=_v) ans2 = min(ans2, abs(GetSum(_x,_y,_u,pos) - GetSum(_x,pos+1,_u,_v)));

    printf("%d\n", min(ans1,ans2));

}

int main()
{
    init();
    FOR(i,0,_k)
    {
        implement(k[i].x, k[i].y, k[i].u, k[i].v);
    }
}
