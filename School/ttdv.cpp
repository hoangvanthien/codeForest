/*
    github.com/hoangvanthien
    Thien Van Hoang
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

int n, m, c[maxN][maxN];
LL sum[maxN];

void init()
{
    freopen("ttdv.inp", "r", stdin);
    //freopen("ttdv.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,1,n+1)
    FOR(j,1,n+1)
    if (i!=j) c[i][j] = oo;
    FOR(i,0,m)
    {
        int x,y,_c;
        scanf("%d%d%d", &x, &y, &_c);
        c[x][y] = _c;
        c[y][x] = _c;
    }
}

void print()
{

}

int main()
{
	init();
	FOR(k,1,n+1)
	FOR(u,1,n)
	FOR(v,u+1,n+1)
	{
	    c[u][v] = min(c[u][v], c[u][k] + c[k][v]);
	    c[v][u] = c[u][v];
	}

	FOR(u,1,n+1)
	FOR(v,1,n+1)
	if (c[u][v] != oo) sum[u] += c[u][v];

	int pos = min_element(sum+1, sum+n+1) - sum;
	printf("%d\n%d", pos, sum[pos]);
}
