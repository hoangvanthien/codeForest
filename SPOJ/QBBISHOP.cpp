#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 205
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define iiI pair<pair<int,int>, int>
#define LL long long

int n,m;
II s,t;
queue<iiI> q;
bool obs[maxN][maxN], tt[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    int x,y,u,v;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &u, &v);
    x = n-x+1; u = n-u+1;
    s = mp(x,y);
    t = mp(u,v);
    if (m)
        FOR(i,1,m)
        {
            scanf("%d%d", &x, &y);
            x = n-x+1;
            obs[x][y] = true;
        }
}
inline bool ok(int x, int y)
{
    if (x && x<=n && y && y<=n)
        return !obs[x][y];
    else return false;
}

void BFS()
{
    q = queue<iiI>();
    q.push(mp(s,0));
    do
    {
        iiI next = q.front();
        q.pop();
        II coor = next.F;
        if (coor == t)
        {
            printf("%d", next.S);
            exit(0);
        }
        FOR(i,-1,1)
        FOR(j,-1,1)
            if (abs(i) == abs(j) && abs(i) == 1)
                for(int k = 1; ok(coor.F+k*i, coor.S+k*j); ++k)
                {
                    int x = coor.F+k*i, y = coor.S+k*j;
                    if (!tt[x][y])
                    {
                        q.push(mp(mp(x,y), next.S+1));
                        tt[x][y] = true;
                    }
                }
    } while (!q.empty());
    printf("-1");
}

int main()
{
	init();
	BFS();
}
