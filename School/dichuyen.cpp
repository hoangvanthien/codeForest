#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 102
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

set<II> s;
int n, c[maxN][maxN], t[maxN][maxN], d[maxN], f[maxN], maxT;

void init()
{
    freopen("dichuyen.inp", "r", stdin);
    freopen("dichuyen.out", "w", stdout);
    scanf("%d%d", &n, &maxT);
    FOR(i,1,n) FOR(j,1,n) scanf("%d", &t[i][j]);
    FOR(i,1,n) FOR(j,1,n) scanf("%d", &c[i][j]);
}

int main()
{
	init();
	s.clear();
	s.insert(mp(0,1));
	FOR(i,2,n) d[i] = f[i] = oo;
	while (!s.empty())
	{
		II top = *(s.begin());
		s.erase(top);
		int u = top.S;
		FOR(v,1,n)
		if (v!=n)
		{
		    if ((d[v] > d[u] + c[u][v] || f[u] + t[u][v] < f[v]) && f[u] + t[u][v] <= maxT)
            {
                s.erase(mp(d[v], v));
                d[v] = d[u] + c[u][v];
                f[v] = f[u] + t[u][v];
                s.insert(mp(d[v], v));
            }
		}
		else
        {
             if (d[v] > d[u] + c[u][v] && f[u] + t[u][v] <= maxT )
            {
                s.erase(mp(d[v], v));
                d[v] = d[u] + c[u][v];
                f[v] = f[u] + t[u][v];
                s.insert(mp(d[v], v));
            }
        }
	}
	printf("%d %d", d[n], f[n]);
}
