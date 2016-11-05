#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i=(x); i<(y); ++i)
#define maxN 1001
#define maxM 25001
#define oo 10000007

int n,m, c[maxN][maxN], order[maxN][maxN], d[maxN], trace[maxN], sumall;
vector<int> answer;
bool tt[maxN];

void init()
{
	freopen("ELECTRIC.INP", "r", stdin);
	scanf("%d%d", &n, &m);
	FOR(i,1,n+1)
	FOR(j,1,n+1)
	if (i!=j)
		c[i][j] = oo;
	FOR(i,0,m)
	{
		int u,v,_c;
		scanf("%d%d%d", &u, &v, &_c);
		c[u][v] = -_c;
		c[v][u] = -_c;
		sumall += _c;
		order[u][v] = i+1;
		order[v][u] = order[u][v];
	}
	FOR(i,1,n+1)
	{
		d[i] = oo;
		tt[i] = false;
	}
	d[1] = -oo;
}

void prim()
{
	int u = 1;

	FOR(k,1,n+1)
	{
		tt[u] = true;
		int Min = oo;
		int _u;
		FOR(v,1,n+1)
		if (tt[v] == false)
		{
			if (c[u][v] < d[v])
			{
				d[v] = c[u][v];
				trace[v] = u;
			}
			if (d[v] < Min)
			{
				_u = v;
				Min = d[v];
			}
		}
		u = _u;
	}
}

void print()
{
    freopen("ELECTRIC.OUT", "w", stdout);
	int weight = 0;
	FOR(i,2,n+1)
	{
		//printf("(%d, %d)\n", i, trace[i]);
		weight += c[i][ trace[i] ];
		answer.push_back(order[i][ trace[i] ]);
	}
	sort(answer.begin(), answer.end());
	printf("%d\n", -weight);
	FOR(i,0,answer.size())
	{
        printf("%d\n", answer[i]);
	}


}

int main()
{

        init();
        prim();
        print();

}
