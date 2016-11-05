/*
    github.com/hoangvanthien
    Thien Van Hoang
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,s,t,d[maxN];
vector<II> dsk[maxN];

void init()
{
    freopen("minpath.inp", "r", stdin);
    freopen("minpath.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i,0,m)
    {
        int u,v,c;
        scanf("%d%d%d", &u, &v, &c);
        dsk[u].pb(mp(v,c));
        dsk[v].pb(mp(u,c));
    }
    FOR(i,1,n+1) d[i] = oo;
    d[s] = 0;
}

void dijkstra()
{
    set<II> _s;
    _s.clear();
    _s.insert(mp(d[s],s));
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
                _s.erase(mp(d[v], v));
                d[v] = d[u] + w;
                _s.insert(mp(d[v], v));
            }
        }
    }
    printf("%d", d[t]);
}

int main()
{
	init();
	dijkstra();
}
