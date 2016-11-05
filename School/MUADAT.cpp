#include <bits/stdc++.h>
using namespace std;

#define oo 100000007
#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define maxN 101
#define mp make_pair
#define pb push_back
#define II pair<int, int>
#define F first
#define S second

II Map[maxN*maxN];
vector< int > Queue;
vector< int > dsk[maxN*maxN];

int ar[maxN][maxN], Size, mincol, minrow, MS, MC, MR, m, n, Count;
bool tt[maxN*maxN];

inline int index(int x, int y)
{
    return (x-1)*n+y;
}

inline int GetCol(int index)
{
    if (index%n == 0) return n;
    else return index%n;
}

inline int GetRow(int index)
{
    if (index%n == 0) return index/n;
    else return index/n+1;
}

void init()
{
    freopen("MUADAT.INP","r",stdin);
    freopen("MUADAT.OUT","w",stdout);
    scanf("%d%d", &m, &n);
    FOR(i,1,m)
    FOR(j,1,n)
    {
        scanf("%d", &ar[i][j]);
    }
    FOR(i,1,m)
    FOR(j,1,n)
    {
        int cur_val = ar[i][j];
        if (ar[i-1][j] == cur_val) dsk[(i-1)*n+j].pb(index(i-1,j));
        if (ar[i][j-1] == cur_val) dsk[(i-1)*n+j].pb(index(i,j-1));
        if (ar[i+1][j] == cur_val) dsk[(i-1)*n+j].pb(index(i+1,j));
        if (ar[i][j+1] == cur_val) dsk[(i-1)*n+j].pb(index(i,j+1));
        //if (dsk[index(i,j)].size()>0)
        //FOR(k,0,dsk[index(i,j)].size()-1)
        //printf("%d ",dsk[index(i,j)][k]);
        //printf("\n");
    }
    Queue.reserve(n);
}

void BFS(int i, int j)
{
    Queue.pb(index(i,j));
    int first = 0;
    tt[(index(i,j))] = true;
    Size = 1;
    mincol = j;
    minrow = i;
    int u,v;
    do
    {
        u = Queue[first];
        first ++;
        if (dsk[u].size() >0)
        FOR(i,0,dsk[u].size()-1)
        {
            v = dsk[u][i];
            if (tt[v] == false)
            {
                tt[v] = true;
                Size ++;
                int col = GetCol(v);
                int row = GetRow(v);
                if (row<minrow || (row==minrow && col<mincol))
                {
                    mincol = col;
                    minrow = row;
                }
                Queue.pb(v);
            }
        }
    }
    while (Queue.size() >= first + 1);

    Queue.resize(0);

}

void print()
{
    printf("%d\n", Count);
    printf("%d %d\n", MR, MC);
    printf("%d", MS);
}

int main()
{
    MS = 0;
    init();
    FOR(i,1,m)
    FOR(j,1,n)
    if (tt[index(i,j)] == false)
    {
        BFS(i,j);
        if (Size>MS)
        {
            MS = Size;
            MR = minrow;
            MC = mincol;
        }
        Count++;
    }
    print();
}
