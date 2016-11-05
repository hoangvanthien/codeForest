#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 21
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,c[maxN][maxN],trace[maxN],f[maxN][1<<maxN];

void init()
{
    freopen("duongdi.inp", "r", stdin);
    freopen("duongdi.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        c[u][v] = c[v][u] = 1;
    }
}

void print(int u)
{
    if (u==0) return;
    print(trace[u]);
    printf("%d ", u);
}

void dp(int u, int cnt, int d)
{
    if (f[u][d]) return;
    f[u][d] = true;
    if (u == n)
    {
        if (cnt == n)
        {
            print(n);
            exit(0);
        }
        return;
    }
    FOR(v,1,n)
<<<<<<< HEAD
    if (!(d & (1<<(v-1))) && c[u][v])
    {
        trace[v] = u;
        dp(v, cnt+1, d | (1<<(v-1)));
=======
    if (!(d & (1<<(v-1))) && c[u][v]) // check if v in d
    {
        trace[v] = u;
        dp(v, cnt+1, d | (1<<(v-1))); // turn on v
>>>>>>> origin/master
    }
}

int main()
{
	init();
    dp(1,1,1);
    printf("-1\n");
}
