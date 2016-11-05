#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i= (x); i<=(y); ++i)
#define maxN 105
#define pb push_back

int m,n,Size,ar[maxN][maxN];
vector<int> Queue;
vector<int> dsk[maxN*maxN];
bool tt[maxN*maxN];

inline int index(int x, int y)
{
    return (x-1)*n+y;
}
inline int GetCol(int index)
{
    if (index%n==0) return n;
    else return index%n;
}
inline int GetRow(int index)
{
    if (index%n==0) return index/n;
    else return index/n+1;
}

void init()
{
    freopen("HONUOC.INP","r",stdin);
    freopen("HONUOC.OUT", "w", stdout);
    scanf("%d%d", &m,&n);

    FOR(i,1,m)
    FOR(j,1,n)
    {
        scanf("%d", &ar[i][j]);
    }
    FOR(i,1,m)
    FOR(j,1,n)
    {
        int cur_val = ar[i][j];
        if (cur_val == 0)
        {
            ar[i][j] = -1;
            continue;
        }
        if (ar[i-1][j] == cur_val) dsk[(i-1)*n+j].pb(index(i-1,j));
        if (ar[i][j-1] == cur_val) dsk[(i-1)*n+j].pb(index(i,j-1));
        if (ar[i+1][j] == cur_val) dsk[(i-1)*n+j].pb(index(i+1,j));
        if (ar[i][j+1] == cur_val) dsk[(i-1)*n+j].pb(index(i,j+1));
    }
    Queue.reserve(m*n);
    Size = 0;
}

void BFS(int i, int j)
{
    bool dec = false;
    int _size = 0;
    Queue.pb(index(i,j));
    int first = 0;
    tt[(index(i,j))] = true;
    _size ++;
    int u,v;
    do
    {
        u = Queue[first];
        int col = GetCol(u);
        int row = GetRow(u);
        if ((col == n || col == 1 || row == 1 || row == m) && dec == false)
            dec = true;
        first ++;
        if (dsk[u].size() >0)
        FOR(i,0,dsk[u].size()-1)
        {
            v = dsk[u][i];
            if (tt[v] == false)
            {
                tt[v] = true;
                _size ++;
                Queue.pb(v);
            }
        }
    }
    while (Queue.size() >= first + 1);
    Queue.resize(0);
    if (dec) ; else Size += _size;
}

int main()
{
    init();
    FOR(i,1,m)
    FOR(j,1,n)
    if (tt[index(i,j)] == false && ar[i][j] == 1)
    {
        BFS(i,j);
    }
    printf("%d", Size);
}
