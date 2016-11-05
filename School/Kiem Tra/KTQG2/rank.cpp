#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

//struct player
//{
//    int Rank;
//    bool operator < (const player &b) const
//    {
//        return (Rank < b.Rank);
//    }
//};

map<int, int> id;
bool tt[maxN];
int a[maxN], N, r[maxN],m,n,deg[maxN],lis[maxN], lis_id[maxN];
vector<int> order, dsk[maxN];
//player pl[maxN];

//bool Min(int )

void init()
{
    freopen("rank.inp", "r", stdin);
    freopen("rank.out", "w", stdout);
    scanf("%d%d", &n, &m);
    N = 0;
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        if (id[u] == 0) id[u] = ++N;
        if (id[v] == 0) id[v] = ++N;
        dsk[id[u]].pb(id[v]);
        ++deg[id[v]];
    }
    FOR(i,1,n)
    {
        int x;
        scanf("%d", &x);
        if (id[x] == 0) id[x] = ++N;
        a[i] = id[x];
    }
}

void Numbering()
{
    queue<int> q;
    int cnt = 0;
    FOR(i,1,N) if (deg[i] == 0)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        order.pb(u);
        r[u] = ++cnt;
        q.pop();
        forit(it, dsk[u])
        {
            int v = *it;
            --deg[v];
            if (deg[v] == 0)
            {
                q.push(v);
                deg[v] = -1;
            }
        }
    }
}

int main()
{
	init();
	Numbering();
    FOR(i,1,n) a[i] = r[a[i]];
    int l = 0;
    FOR(i,1,n)
    {
        int pos = lower_bound(lis, lis+l, a[i]) - lis;
        lis[pos] = a[i];
//        lis_id[pos] = i;
//        trace[i] = (pos > 0) ? lis_id[pos-1] : -1;
        if (l == pos) ++l;
    }
    printf("%d", (N-l)*2);
}
