#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 3003
#define maxR 11
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,r[maxN],c[maxN][maxN],d[maxN];
vector<II> dsk[maxN];
II ar[maxN];

void init()
{
    freopen("input.inp", "r", stdin);
    //freopen("server.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%d", &r[i]);
//    FOR(i,1,n)
//    FOR(j,1,n)
//    if (i!=j)
//        c[i][j] = oo;
    FOR(i,1,m)
    {
        int a,b,t;
        scanf("%d%d%d", &a, &b, &t);
//        c[a][b] = c[b][a] = t;
        dsk[a].pb(mp(b,t));
        dsk[b].pb(mp(a,t));
    }
}

void print()
{

}

void dijkstra(int s)
{
    FOR(i,1,n) d[i] = oo;
    d[s] = 0;
    set<II> _s;
    _s.clear();
    _s.insert(mp(d[s], s));
    while (!_s.empty())
    {
        II top = *(_s.begin());
        _s.erase(top);
        int u = top.S;
        if (dsk[u].size()>0)
        FOR(i,0,dsk[u].size()-1)
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
}

int main()
{
	init();
	int ans = 0;
//	FOR(i,1,n)
//	FOR(u,1,n)
//	FOR(v,1,n)
//        c[u][v] = min(c[u][v], c[u][i] + c[i][v]);

//    FOR(v,1,n)
//    FOR(w,1,n)
//    if (r[w] >= r[v])
//    {
//        bool ok = true;
//        FOR(u,1,n)
//        if (c[v][u] <= c[v][w])
//            if (!(r[w] >= r[u]))
//            {
//                ok = false;
//                break;
//            }
//        if (ok)
//        {
//            //db(v); db(w);
//            ans++;
//        }
//    }
    FOR(u,1,n)
    {
        dijkstra(u);
//        db(u);
//        FOR(i,1,n) ar[i] = mp(d[i], max(r[i], ar[i-1].S));
        FOR(i,1,n) ar[i] = mp(d[i], i);
        sort(ar+1, ar+1+n);
        FOR(i,1,n) ar[i].S = max(r[ar[i].S], ar[i-1].S);
        FOR(w,1,n)
        {
            int pos = upper_bound(ar+1, ar+1+n, mp(d[w], maxR)) - ar;
            if (--pos>0)
                if (ar[pos].S <= r[w])
                {
//                    db(w);
                    ans++;
                }
        }
    }
    printf("%d", ans);
}
