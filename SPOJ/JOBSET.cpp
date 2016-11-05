#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN], n, m, cnt, trace[maxN], delta[maxN], ans, Sum, c[maxN][maxN], f[maxN][maxN];
std::vector<int> dsk[maxN], topo, root, sum, tree[maxN];

void init()
{
    freopen("jobset.inp", "r", stdin);
    freopen("jobset.out", "w", stdout);
    scanf("%d", &n);
    FOR(i,2,n+1)
    {
        scanf("%d", &a[i]);
        if (a[i] > 0)
        {
            dsk[1].pb(i);
            Sum += a[i];
            c[1][i] = a[i];
        }
        else
        {
            dsk[i].pb(n+2);
            c[i][n+2] = -a[i];
        }
    }
    scanf("%d", &m);
    //FOR(i,1,n) FOR(j,1,n) c[i][j] = (i!=j) ? oo : 0;
    FOR(i,1,m)
    {
    	int u,v;
    	scanf("%d%d", &u, &v);
    	dsk[u+1].pb(v+1);
    	c[u+1][v+1] = Sum + 1;
    	//dsk[v].pb(u);
    }
}

bool FindPath()
{
    FOR(i,1,n+2) trace[i] = 0;
    trace[1] = 1;
    delta[1] = oo;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        FOR(v,1,n+2)
        if (trace[v] == 0)
        {
            //int v = *it;
            if (c[u][v] > f[u][v])
            {
                trace[v] = u;
                delta[v] = min(delta[u], c[u][v] - f[u][v]);
                q.push(v);
            }
            else
                if (f[v][u] > 0)
                {
                    trace[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    q.push(v);
                }
        }
    }
    return (trace[n+2] != 0);
}

void IncFlow()
{
    int v = n+2;
    while (v!=1)
    {
        int u = trace[v];
        if (u>0) f[u][v] += delta[n+2]; else
        {
            u = -u;
            f[v][u] -= delta[n+2];
        }
        v = u;
    }
}

int main()
{
	init();
	while (FindPath())
        IncFlow();
	int w = 0;
	FOR(i,1,n+2) w += f[1][i];
	printf("%d", Sum - w);
}

