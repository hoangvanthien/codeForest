#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m;
vector<int> pset;

void init()
{
    freopen("NETWORK2.INP", "r", stdin);
    freopen("NETWORK2.OUT", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i,0,n-1) pset.pb(i);
}

int findSet(int i)
{
    return (pset[i] == i ? i : pset[i] = findSet(pset[i]));
}

int unionSet(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j)
{
    return (findSet(i) == findSet(j));
}

int main()
{
	init();
	char ch;
	int yes = 0, q = 0;
	FOR(i,1,m)
	{
	    int u,v;
	    scanf("%c", &ch);
	    scanf("%c %d %d", &ch, &u, &v);
	    --u; --v;
	    if (ch == 'c')
        {
            unionSet(u,v);
            continue;
        }
        ++q;
        yes += isSameSet(u, v);
	}
	printf("%d %d", yes, q-yes);
}
