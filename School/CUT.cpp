#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

vector<pair<int, bool> > dsk[maxN];
int n,m,parent[maxN],low[maxN],number[maxN],cnt,cntChild[maxN];
bool iscut[maxN];

void init()
{
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("CUT.inp", "r", stdin);
    freopen("CUT.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        dsk[u].pb(mp(v,true));
        dsk[v].pb(mp(u,true));
    }
    FOR(i,1,n) sort(dsk[i].begin(), dsk[i].end());
}

void visit(int u)
{
    ++cnt; number[u] = cnt;
    low[u] = n+1;

    if (dsk[u].size()>0)
    forit(it, dsk[u])
    if ((*it).S)
    {
        (*it).S = false;
        int v = (*it).F;
        int pos = lower_bound(dsk[v].begin(), dsk[v].end(), mp(u,false)) - dsk[v].begin();
        dsk[v][pos].S = false;
        if (!parent[v])
        {
            parent[v] = u;
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], number[v]);
    }
}

void print()
{
    FOR(i,1,n)
    if (parent[i] != -1) cntChild[parent[i]]++;
    cnt = 0;
    FOR(v,1,n)
    {
        if (parent[v]!=-1 && low[v] >= number[v]) ++cnt;
    }
    printf("%d ", cnt);
    cnt = 0;
    FOR(v,1,n)
    if (parent[v] != -1)
    {
        int u = parent[v];
        if (low[v] >= number[u])
            iscut[u] = iscut[u] || parent[u]!=-1 || cntChild[u]>=2;
    }
    FOR(v,1,n)
    if (iscut[v]) ++cnt;
    printf("%d\n", cnt);

    FOR(v,1,n)
    {
        if (parent[v]!=-1 && low[v] >= number[v]) printf("%d %d\n", parent[v], v);
    }
    FOR(v,1,n)
    if (iscut[v]) printf("%d\n", v);
}

int main()
{
	init();
	FOR(u,1,n)
	if (!parent[u])
    {
        parent[u] = -1;
        visit(u);
    }
    print();
}
