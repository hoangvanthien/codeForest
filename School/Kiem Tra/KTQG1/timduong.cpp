#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define pb push_back
#define maxN 500005
#define oo 1e9

int n,h,a[maxN/2],b[maxN/2],h1[maxN],h2[maxN],_h[maxN];

void init()
{
    freopen("timduong.inp", "r", stdin);
    freopen("timduong.out", "w", stdout);
    scanf("%d%d", &n, &h);
    FOR(i,0,n/2) scanf("%d%d", &a[i], &b[i]);

    sort(a, a+n/2);
    sort(b, b+n/2);
}

int main()
{
    init();
    DFOR(i,n/2-1,-1)
    {
        h1[a[i]] = h1[a[i+1]] + 1;
    }

    DFOR(k,a[0]-1,0) h1[k] = h1[a[0]]; // a[0] - 1 ... 1

    DFOR(i,n/2-1,-1)
    {
        h2[h-b[i]+1] = h2[h-b[i+1]+1] + 1;
    }

    DFOR(k,h,h-b[0]+1) h2[k] = h2[h-b[0]+1];

    int Min = oo;
    FOR(i,1,h+1)
    {
        _h[i] = h1[i] + h2[i];
        Min = min(Min, _h[i]);
    }
    int Count = 0;
    FOR(i,1,h+1)
    if (_h[i] == Min) Count ++;
    printf("%d %d", Min, Count);
}
