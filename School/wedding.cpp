#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define pop pop_back
#define maxN 100001
#define maxM 1000001

vector< std::vector<int> > ar(4000);
vector<int> Stack;
int trace[maxM];
bool tt[maxM];
int m,n,s,f;

void init()
{
	FILE * pFile;
	pFile = fopen("wedding.inp", "r");
	fscanf(pFile, "%d", &n);
	for (int i=0; i<2*n; ++i)
	{
		int x;
		fscanf(pFile, "%d", &x);
		for (int j=0; j<x; ++j) 
		{
			int y;
			fscanf(pFIle, "%d", &y);
			ar[i].pb(y);
		}
	}
}

void print()
{
    FILE * pFile;
    pFile = fopen("dfs.out", "w");
    vector<int> ans;
    int j = f;
    while (j!=0 && j!=n+1)
    {
        ans.pb(j);
        j = trace[j];
    }

    fprintf(pFile, "%d", ans[ans.size()-1]);
    for (int i=ans.size()-2; i>=0; --i)
    {
        fprintf(pFile, " %d", ans[i]);
    }
}

void DFS()
{
    Stack.pb(s);
    trace[s] = n+1;
    tt[s] = true;
    int u,v;
    do
    {
        u = Stack[Stack.size()-1];
        if (u==f) print();
        Stack.pop();
        for (int i=0; i<ar[u].size(); ++i)
        {
            v = ar[u][i];
            if (tt[v] == false)
            {
                //v = ar[u][i];
                tt[v] = true;
                trace[v] = u;
                Stack.pb(u);
                Stack.pb(v);
                break;
            }
        }
        //printf("%d\n",u);
    }
    while (Stack.size() != 0);
}

int main()
{

}