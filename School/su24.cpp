#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 105
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int trace[maxN], d[maxN], n, m, cnt;
bool fwd[maxN], tt[maxN];
std::vector<int> dsk[maxN];

void init()
{
    freopen("su24.inp", "r", stdin);
    freopen("su24.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,1,m)
    {
    	int u,v;
    	scanf("%d%d", &u, &v);
    	dsk[u].pb(v);
    }
}

void BFS()
{
	memset(trace, 0, sizeof trace);
	trace[1] = n+1;
	queue<int> q;
	q.push(1);
	do
	{
		int u = q.front();
		q.pop();
		forit(it, dsk[u])
		if (trace[*it] == 0)
		{
			q.push(*it);
			trace[*it] = u;
		}
	} while (!q.empty());
	int f = 2; cnt = 0;
	while (f!=n+1 && f!=0)
	{
		fwd[f] = true;
		++cnt;
		f = trace[f];
	}
	FOR(i,1,n)
	if (fwd[i]) d[i] = cnt; else d[i] = oo;
//	d[i] = oo;
}

void dijkstra()
{
    tt[2] = true;
	set<II> s;

	s.insert(mp(d[2], 2));
	while (!s.empty())
	{
		II p = (*s.begin());
		s.erase(p);
		int u = p.S;
		if (u == 1) break;
		forit(it, dsk[u])
		if (fwd[*it])
        {
            s.erase(mp(d[*it], *it));
            //tt[*it] = true;
            if (d[*it] == cnt) d[*it] = d[u]; else d[*it] = min(d[*it], d[u]);
            s.insert(mp(d[*it], *it));
        }
        else
            if (d[*it] > d[u] + 1)
            {
                s.erase(mp(d[*it], *it));
                d[*it] = d[u] + 1;
                //tt[*it] = true;
                s.insert(mp(d[*it], *it));
            }
	}
}

int main()
{
	init();
	BFS();
	dijkstra();
	printf("%d", d[1]);
}

