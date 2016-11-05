#include <bits/stdc++.h>

using namespace std;

#define maxN 100001
#define maxM 1000001
#define pb push_back
#define pop pop_back

vector< vector<int> > ar(maxN);
vector<int> Queue;
int trace[maxM];
int heavy[maxM];
bool tt[maxM];
int m,n,s,f;

void print()
{
    FILE * pFile;
    pFile = fopen("bfs.out", "w");
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

void BFS()
{
    Queue.pb(s);
    int first = 0;
    trace[s] = n+1;
    tt[s] = true;
    heavy[s] = 1;
    int u,v;
    do
    {
        u = Queue[first];
        first++;
        if (u==f) print();
        //Queue.pop();
        for (int i=0; i<ar[u].size(); ++i)
        {
            v = ar[u][i];
            if (tt[v] == false || (tt[v] && heavy[v] > heavy[u]+1))
            {
                //v = ar[u][i];
                tt[v] = true;
                trace[v] = u;
                heavy[v] = heavy[u] + 1;
                //Queue.pb(u);
                Queue.pb(v);
                //break;
            }
        }
        //printf("%d\n",u);
    }
    while (Queue.size() >= first+1);
}



int main()
{
    FILE *pFile;
    pFile = fopen("bfs.inp","r");
    fscanf(pFile,"%d%d%d%d",&n,&m,&s,&f);


    for (int i=0; i<m; ++i)
    {
        int x,y;
        fscanf(pFile,"%d%d",&x,&y);
        ar[x].pb(y);
    }
    int i;
    for (i=1; i<=n; ++i)
    {
        sort(ar[i].begin(),ar[i].end());
    }

    BFS();
}
