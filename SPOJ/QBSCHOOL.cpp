#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 5007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,d[maxN];
LL way[maxN];
vector<II> dsk[maxN];

void init()
{
    freopen("qbschool.inp", "r", stdin);
    freopen("qbschool.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,0,m)
    {
        int k,u,v,l;
        scanf("%d%d%d%d", &k, &u, &v, &l);
        dsk[u].pb(mp(v,l));
        if (k==2) dsk[v].pb(mp(u,l));
    }
    FOR(i,1,n+1)
    {
        d[i] = oo;
        way[i] = 0;
    }
    d[1] = 0;
    way[1] = 1;
}

void dijkstra()
{
    set<II> _s;
    _s.clear();
    _s.insert(mp(d[1], 1));
    while (!_s.empty())
    {
        II top = *(_s.begin());
        _s.erase(top);
        int u = top.S;
        FOR(i,0,dsk[u].size())
        {
            int v = dsk[u][i].F, w = dsk[u][i].S;
            if (d[v] > d[u] + w)
            {
                way[v] = way[u];
                _s.erase(mp(d[v], v));
                d[v] = d[u] + w;
                _s.insert(mp(d[v], v));
            }
            else
                if (d[v] == d[u] + w)
                {
                    way[v] += way[u];
                }
        }
    }

    printf("%d %lld", d[n], way[n]);
}

int main()
{
	init();
	dijkstra();
}
