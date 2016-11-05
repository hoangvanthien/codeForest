#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 1002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,c[maxN][maxN], f[maxN][maxN],trace[maxN],s,t,delta[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("maxflow.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    s = 1; t = n;
    FOR(i,1,m)
    {
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        c[u][v] = w;
    }
}

bool FindPath()
{
    FOR(i,1,n) trace[i] = 0;
    trace[s] = s;
    delta[s] = oo;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        FOR(v,1,n)
        if (trace[v] == 0)
        {
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
    return (trace[t] != 0);
}

void IncFlow()
{
    int j = t;
    while (j != s)
    {
        int i = trace[j];
        if (i>0) f[i][j] += delta[t]; else f[j][-i] -= delta[t];
        j = i;
    }
}

int main()
{
	init();
	while (FindPath()) IncFlow();
	int w = 0;
	FOR(i,1,n) w += f[1][i];
	printf("%d\n", w);
	FOR(i,1,n) FOR(j,1,n)
	if (f[i][j] > 0) printf("%d %d %d\n", i,j,f[i][j]);
}
