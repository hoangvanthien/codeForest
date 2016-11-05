#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)

void init()
{
    freopen("MAP.INP", "r", stdin);
    freopen("MAP.OUT", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i,1,m)
    FOR(j,1,n+1)
    {
        char c;
        scanf("%c", &c);
        if (c=='.') ar[i][j] = 0;
        if (c=='X') ar[i][j] = 1;
    }
}

void DFS(int i, int j)
{
    if (!(1<=i && i<=m && 1<=j && j<=n)) return;
    if (ar[i][j] == 2) return;
    ar[i][j] = 2;
    DFS(i-1,j);
    DFS(i+1,j);
    DFS(i,j-1);
    DFS(i,j+1);
}

int main()
{
    init();
    FOR(i,1,m)
    FOR(j,1,n)
    if (ar[i][j]=1)
    {
        DFS(i,j);
        break;
    }
}
