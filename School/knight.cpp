#include <bits/stdc++.h>

using namespace std;
#define maxN 10001
#define maxM 10001
#define pb push_back

bool tot[maxN];
vector< vector<int> > ar(maxN);
vector<int> Queue;
//int trace[maxM];
int heavy[maxM];
bool tt[maxM];
int m,n,s,f,sx,sy,fx,fy;
bool Solved;

int Index(int row, int col)
{
	return (row-1)*n+col;
}

void add(int row, int col, int start)
{
	int index = (row-1)*n+col;
	if (1<=row && row<=m && 1<=col && col<=n)
		if (tot[index] == false && tot[start]==false)
	{
		ar[start].pb(index);
		ar[index].pb(start);
	}
}

int init()
{
	FILE * pFile;
	pFile = fopen("knight.inp", "r");
	int k;
	fscanf(pFile, "%d%d%d", &m, &n, &k);
	fscanf(pFile, "%d%d%d%d", &sx, &sy, &fx, &fy);
	for (int i=0; i<k; ++i)
	{
		int x,y;
		fscanf(pFile,"%d%d",&x,&y);
		tot[(x-1)*n+y] = true;
	}

	for (int i=1; i<=m*n; ++i)
		if (tot[i]==false)
		{
			int crow, ccol;
			if (i%n == 0)
            {
                crow = i/n;
                ccol = n;
            }
            else
            {
                crow = i/n + 1;
                ccol = i%n;
            }
			add(crow-2, ccol+1, i);
			add(crow-1, ccol+2, i);
			add(crow+1, ccol+2, i);
			add(crow+2, ccol+1, i);
		}
    /*for (int i=1; i<=m*n; ++i)
    {
        for (int j=0; j<ar[i].size(); ++j) printf("%d ",ar[i][j]);
        printf("\n");
    }*/
	Solved = false;
}

void print(int content)
{
	FILE * pFile;
	pFile = fopen("knight.out", "w");
	fprintf(pFile, "%d", content);
	Solved = true;
	/*int j = f;
	while (j!=0 && j!=n+1)
	{
        fprintf(pFile, "%d\n", j);
        j = trace[j];
	}*/
}

void BFS()
{
	s = Index(sx,sy);
	f = Index(fx,fy);
    Queue.pb(s);
    int first = 0;
    //trace[s] = n+1;
    tt[s] = true;
    heavy[s] = 1;
    int u,v;
    do
    {
        u = Queue[first];
        first++;
        if (u==f)
    	{
    		print(heavy[f]-1);
    		return;
    	}
        for (int i=0; i<ar[u].size(); ++i)
        {
            v = ar[u][i];
            if (tt[v] == false || (tt[v] && heavy[v] > heavy[u]+1))
            {
                tt[v] = true;
                //trace[v] = u;
                heavy[v] = heavy[u] + 1;
                Queue.pb(v);
            }
        }
    }
    while (Queue.size() >= first+1);
}

int main()
{
	init();
	BFS();
	if (Solved == false) print(-1);
}
