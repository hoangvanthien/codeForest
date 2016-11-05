/*
    github.com/hoangvanthien
    Thien Van Hoang
    Accepted Solution
    UVA 10986 - "Sending Email"
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
vector<II > dsk[maxN];
set<II > S;

void dijkstra()
{
    d[s] = 0;
    S.insert(mp(d[s],s));
    while (!S.empty())
    {
        II first = *(S.begin());
        S.erase(first);
        int u = first.S;
        FOR(i,0,dsk[u].size())
        {
            int v = dsk[u][i].F, w = dsk[u][i].S;
            if (d[v] > d[u] + w)
            {
                S.erase(mp(d[v], v));
                d[v] = d[u] + w;
                S.insert(mp(d[v], v));
            }
        }
    }
    if (d[t] == oo)
        printf("unreachable\n");
    else
        printf("%d\n", d[t]);
}

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    int numberOfTest;
    scanf("%d", &numberOfTest);
    FOR(k,0,numberOfTest)
    {
        scanf("%d%d%d%d", &n, &m, &s, &t);
        FOR(i,0,n) dsk[i].clear();
        FOR(i,0,m)
        {
            int u,v,_c;
            scanf("%d%d%d", &u, &v, &_c);
            dsk[u].pb(mp(v,_c));
            dsk[v].pb(mp(u,_c));
        }
        FOR(i,0,n) d[i] = oo;
        S.clear();
        printf("Case #%d: ", k+1);
        dijkstra();
    }
}

void print()
{

}

int main()
{
	init();
}
