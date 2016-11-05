/*
    github.com/hoangvanthien
    Thien Van Hoang
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 10002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,s,f,c[maxN][maxN],d[maxN];
bool tt[maxN];

void init()
{
    freopen("taudien.inp", "r", stdin);
    //freopen("taudien.out", "w", stdout);
    scanf("%d%d%d", &n, &s, &f);
    FOR(i,1,n+1)
    FOR(j,1,n+1)
        if (i!=j) c[i][j] = oo;
    FOR(i,1,n+1)
    {
        int x;
        scanf("%d", &x);
        FOR(j,1,x+1)
        {
            int u;
            scanf("%d", &u);
            if (j==1) c[i][u] = 0; else c[i][u] = 1;
            //c[u][i] = c[i][u];
        }
    }
}

void print()
{

}

void dijkstra()
{
    FOR(i,1,n+1)
    {
        d[i] = oo;
        tt[i] = false;
    }
    d[s] = 0;
    do
    {
        int u = 0, Min = oo;
        FOR(i,1,n+1)
        if (d[i] < Min && !tt[i])
        {
            Min = d[i];
            u = i;
        }
        if (u == 0)
        {
            printf("%d\n", -1);
            exit(0);
        }
        if (u == f)
        {
            printf("%d", d[f]);
            exit(0);
        }
        tt[u] = true;
        FOR(v,1,n+1)
        if (c[u][v] != oo && !tt[v])
        {
            d[v] = min(d[v], d[u] + c[u][v]);
        }
    }
    while (true);
}

int main()
{
	init();
	dijkstra();
}
