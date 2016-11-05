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

vector<int> dsk[maxN];
stack<int> stk;
int cnt,n,m,number[maxN],low[maxN];
bool del[maxN];

void init()
{
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("SCONNECT.inp", "r", stdin);
    freopen("SCONNECT.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        dsk[u].pb(v);
        //dsk[v].pb(u);
    }
}

// Tarjan Algorithm
void visit(int u)
{
    ++cnt; number[u] = cnt;
    low[u] = number[u];
    stk.push(u);
    if (!dsk[u].empty())
    FOR(i,0,dsk[u].size()-1)
    {
        int v = dsk[u][i];
        if (del[v]) continue;
        if (number[v])
        {
            low[u] = min(low[u], number[v]);
        }
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (number[u] == low[u])
    {
        int top;
        do
        {
            top = stk.top();
            printf("%d ", top);
            del[top] = true;
            stk.pop();
        } while (top!=u);
        printf("\n");
    }
}
// end Tarjan

int main()
{
	init();
	cnt = 0;
	FOR(i,1,n)
	if (!number[i])
    {
        //visited[i] = true;
        visit(i);
    }
}
