#include <bits/stdc++.h>
using namespace std;

#define oo 100000007
#define FOR(i,x,y) for (int i = (x); i<=(y); ++i)
#define pb push_back
#define maxN 100001

vector<int> ar[maxN];
vector<int> Queue, Answer;
bool tt[maxN];
int n;

void init()
{
    freopen("ZERO.INP", "r", stdin);
    freopen("ZERO.OUT", "w", stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    {
        FOR(j,1,(int)sqrt(i))
        if (i%j == 0)
        {
            ar[i].pb((j-1)*(i/j+1));
            //printf("%d ", ar[i][ar[i].size()-1]);
        }
        //printf("\n");
    }
}

void BFS()
{
    Queue.reserve(maxN);
    int s = n;
    Queue.pb(s);
    int first = 0;
    tt[s] = true;
    int u,v;
    do
    {
        u = Queue[first];
        first ++;
        if (u==0) continue;
        FOR(i,0,ar[u].size()-1)
        {
            v = ar[u][i];
            if (tt[v] == false)
            {
                tt[v] = true;
                Answer.pb(v);
                Queue.pb(v);
            }
        }
    }
    while (Queue.size()>=first+1);

    sort(Answer.begin(), Answer.end());
}

void print()
{
    printf("%d\n", Answer.size());
    FOR(i,0,Answer.size()-1)
    {
        if (i%10 == 0 && i!=0) printf("\n");
        printf("%d ", Answer[i]);
    }
}

int main()
{
    init();
    BFS();
    print();
}
