/*
    github.com/hoangvanthien
*/
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

int n, a[maxN][maxN], high, ans, Min, Max;
bool found, tt[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,0,n)
    FOR(j,0,n) scanf("%d", &a[i][j]);
}

void DFS(int x, int y)
{
    tt[x][y] = true;
    if (found) return;
    if (x==n-1 && y==n-1)
    {
        found = true;
        return;
    }

    if (x<n-1 && Min<=a[x+1][y] && a[x+1][y]<=Max && !tt[x+1][y])
    {
        DFS(x+1, y);
        if (found) return;
    }
    if (y<n-1 && Min<=a[x][y+1] && a[x][y+1]<=Max && !tt[x][y+1])
    {
        DFS(x, y+1);
        if (found) return;
    }
    if (x>0 && Min<=a[x-1][y] && a[x-1][y]<=Max && !tt[x-1][y])
    {
        DFS(x-1, y);
        if (found) return;
    }
    if (y>0 && Min<=a[x][y-1] && a[x][y-1]<=Max && !tt[x][y-1])
    {
        DFS(x, y-1);
        if (found) return;
    }
}

void print()
{
    printf("%d", ans);
}

bool possible(int d) //distance
{
    FOR(k,0,min(a[0][0], a[n-1][n-1])+1)
    {
        found = false;
        Min = k; Max = k+d;
        FOR(i,0,n) FOR(j,0,n) tt[i][j] = false;
        DFS(0,0);
        if (found) return true;
    }
    return false;
}

int main()
{
    init();
    int l = 0;
    int r = 110;
    while (l<=r)
    {
        high = (l+r)/2;
        if (possible(high))
        {
            r = high - 1;
            ans = high;
        }
        else l = high + 1;
    }
    print();

}


