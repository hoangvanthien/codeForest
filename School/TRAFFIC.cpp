#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for (int i = (x); i<(y); ++i)
#define maxN 1001
#define maxK 1001*1001
#define pb push_back
#define oo 10000007

int n,k,c[maxN][maxN],addition, trace[maxN], d[maxN];
bool b[maxN][maxN], tt[maxN];
vector<int> dsk[maxN];

void init()
{
    freopen("TRAFFIC.INP", "r", stdin);
    scanf("%d%d", &n, &k);
    FOR(i,2,n+1)
    {
        d[i] = oo;
    }

    FOR(i,0,k)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        b[u][v] = true;
        b[v][u] = b[u][v];

    }

    FOR(i,0,n)
    FOR(j,0,n)
    {
        scanf("%d",&c[i+1][j+1]);
        dsk[i+1].pb(j+1);
    }


}

void Prim()
{
    int u = 1;
    FOR(k,1,n+1)
    {
        tt[u] = true;
        int _u = -1;
        int Min = oo;
        FOR(v,1,n+1)
        if (tt[v] == false)
        {
            if (d[v] > c[u][v])
            {
                d[v] = c[u][v];
                trace[v] = u;
            }
            if (b[u][v] == true)
            {
                d[v] = 0;
                trace[v] = u;
            }
            if (Min > d[v])
            {
                Min = d[v];
                _u = v;
            }
        }
        if (_u == -1) // khong co duong di
        {

        }
        else
            u = _u;
    }
}

void print()
{
    FOR(u,2,n+1)
    if (b[u][trace[u]] == false) addition += c[u][trace[u]];
    freopen("TRAFFIC.OUT", "w", stdout);
    if (addition == 0) printf("YES");
    else printf("%d", addition);
}

int main()
{
    init();
    Prim();
    print();
}
