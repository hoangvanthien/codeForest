/*
    github.com/hoangvanthien
    Thien Van Hoang
    UVA 10806 - "Dijkstra, Dijkstra"
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 1002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,d[maxN],trace[maxN],c[maxN][maxN],weight;
vector<int> dsk[maxN];
set<II> S;

void dijkstra(const int time)
{
    d[1] = 0;
    trace[1] = n+1;
    S.insert(mp(d[1], 1));
    while (!S.empty())
    {
        II top = *(S.begin());
        S.erase(top);
        int u = top.S;
        FOR(i,0,dsk[u].size())
        {
            int v = dsk[u][i], w = c[u][v];
            if (d[v] > d[u] + w)
            {
                trace[v] = u;
                S.erase(mp(d[v],v));
                d[v] = d[u] + w;
                S.insert(mp(d[v],v));
            }
        }
    }
    if (d[n] == oo) printf("Back to jail\n");
    else
    {
        weight += d[n];
        if (time == 2)
        {
            printf("%d\n", weight);
            return;
        }
        S.clear();
        FOR(i,1,n+1) d[i] = oo;
        int u = n;
        while (u!=1)
        {
            c[u][trace[u]] = c[trace[u]][u] = oo;
            u = trace[u];
        }
        dijkstra(2);
    }
}

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    while (true)
    {
        scanf("%d", &n);
        if (n==0) break;
        FOR(i,1,n+1)
        {
            dsk[i].clear();
            FOR(j,1,n+1)
            if (i!=j) c[i][j] = oo;
        }
        scanf("%d", &m);
        FOR(i,0,m)
        {
            int u,v,_c;
            scanf("%d%d%d", &u, &v, &_c);
            dsk[u].pb(v);
            dsk[v].pb(u);
            c[u][v] = c[v][u] = _c;
        }
        S.clear();
        FOR(i,1,n+1) d[i] = oo;
        weight = 0;
        dijkstra(1);
    }
}

void print()
{

}

int main()
{
	init();
}
