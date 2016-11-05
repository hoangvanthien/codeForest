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

bool visited[maxN];
int n,m;
vector<int> dsk[maxN];

void init()
{
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("CONNECT.inp", "r", stdin);
    freopen("CONNECT.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
}

void visit(int u)
{
    printf("%d ", u);
    if (dsk[u].size()>0)
    FOR(i, 0, dsk[u].size()-1)
    {
        int v = dsk[u][i];
        if (!visited[v])
        {
            visited[v] = true;
            visit(v);
        }
    }
}

int main()
{
	init();
    FOR(i,1,n)
    if (!visited[i])
    {
        visited[i] = true;
        visit(i);
        printf("\n");
    }
}
