#include <bits/stdc++.h>

using namespace std;
#define maxN 1000*1000+1
#define pb push_back

bool obc[maxN];
vector< vector<int> > ar(maxN);
vector<int> Queue;
vector<int> direction;
int trace[maxN];
int heavy[maxN];
bool tt[maxN];
int m,n,s,f,sx,sy,fx,fy;


int Index(int row, int col)
{
	return (row-1)*n+col;
}

inline void add(int index, int start)
{
    if (1<=index && index<=m*n)
    if (obc[index] == false && obc[start]==false)
    {
        ar[start].pb(index);
        //printf("%d ",index);
    }


}

void print()
{
    FILE *pfile;
	pfile = fopen("robo.out","w");
	fprintf(pfile, "%d", heavy[f]-1);
	/*int j = f;
	while (j!=0 && j!=n+1)
    {
        fprintf(pfile, "%d ", j);
        j = trace[j];
    }*/
}

void init()
{
	//FILE *pfile;
	//pfile = fopen("robo.inp","r");

	freopen("robo.inp","r",stdin);

	scanf("%d %d", &m, &n);
	scanf("%d %d %d %d", &sx,&sy,&fx,&fy);
	direction = {n+1, 1, n};
	int x,y;
	//int k;
	//scanf("%d",&k);
	while (scanf("%d %d",&x,&y) != EOF)
	//for (int i=0; i<k; ++i)
	{
	    //scanf("%d %d",&x,&y);
		obc[(x-1)*n+y] = true;
		/*int i=(x-1)*n+y;
		add(i, i-n-1);
		add(i, i-1);
		add(i, i-n);*/
	}
}

void BFS()
{
	s = Index(sx,sy);
	f = Index(fx,fy);
    Queue.pb(s);
    int first = 0;
    trace[s] = n+1;
    tt[s] = true;
    heavy[s] = 1;
    int u;
    do
    {
        u = Queue[first];
        first++;
        if (u==f)
    	{
    		print();
    		return;
    	}
        for (int i=0; i<direction.size(); ++i)
        {
            int v = u+direction[i];
            if (v<1 || v>m*n) continue;
            if (obc[v] == false)
            {
                if (tt[v] == false || (tt[v] && heavy[v] > heavy[u]+1))
                {
                    tt[v] = true;
                    trace[v] = u;
                    heavy[v] = heavy[u] + 1;
                    Queue.pb(v);
                }
            }
        }
    }
    while (Queue.size() >= first+1);
}

int main()
{
    init();
    BFS();
    print();
}
