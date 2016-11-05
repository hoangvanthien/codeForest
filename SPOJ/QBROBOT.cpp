/*
    github.com/hoangvanthien
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 501
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n, e[maxN], m, tmax;
vector< pair<int, pair<int,int> > > dsk[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,1,n+1) scanf("%d", &e[i]);
    scanf("%d", &m);
    FOR(i,0,m)
    {
        int x,y,t,c;
        scanf("%d%d%d%d", &x, &y, &t, &c);
        dsk[x].pb(mp(y,mp(t,c)));
        dsk[y].pb(mp(x,mp(t,c)));
        if (t>tmax) tmax = t;
    }
}

void print()
{

}

int main()
{

}
