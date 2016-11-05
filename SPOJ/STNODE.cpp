#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 10002
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,s,f,trace[maxN],order[maxN];
queue<int> q;
vector<int> dsk[maxN];
deque<int> path;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &s, &f);
    FOR(i,1,m)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        dsk[u].pb(v);
        //dsk[v].pb(u);
    }
}

void bfs(int start)
{
    memset(trace, 0, sizeof trace);
    trace[start] = n+1;
    q = queue<int>();
    q.push(start);
    do
    {
        int u = q.front();
        if (u == f) break;
        q.pop();
        if (dsk[u].size()>0)
        FOR(i,0,dsk[u].size()-1)
        {
            int v = dsk[u][i];
            if (trace[v] ==0)
            {
                trace[v] = u;
                q.push(v);
            }
        }
    } while (!q.empty());
    int x = f;
    while (x!=n+1 && x!=0)
    {
        path.pf(x);
        x = trace[x];
    }
    FOR(i,0,path.size()-1) order[path[i]] = i+1;
}

bool bfs(int start, int exc)
{
    FOR(i,1,n) trace[i] = 0;
    trace[start] = n+1;
    q = queue<int>();
    q.push(start);
    do
    {
        int u = q.front();
        if (order[u]>order[exc]) return true;
        q.pop();
        if (dsk[u].size()>0)
        {
            FOR(i,0,dsk[u].size()-1)
            {
                int v = dsk[u][i];
                if (trace[v] == 0 && v != exc)
                {
                    trace[v] = u;
                    q.push(v);
                }
            }
        }
    } while (!q.empty());
    return false;
}

int main()
{
	init();
	bfs(s);
	int ans = 0;
	FOR(i,1,path.size()-2)
	{
	    //db(path[i]);
	    int temp = bfs(s, path[i]);
	    //db(temp);
	    if (temp == 0) s = path[i];
	    ans += 1-temp;
	}
	printf("%d", ans);
}
