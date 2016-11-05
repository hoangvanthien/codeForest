#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 1002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN], b[maxN], f[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
}

void print()
{

}

int main()
{
	init();
	int n,x;
	scanf("%d", &n);
	FOR(i,1,n)
	{
	    scanf("%d", &x);
	    a[x] = i;
	}
	while (scanf("%d", &x) != EOF)
    {
        b[x] = 1;
        FOR(i,2,n)
        {
            scanf("%d", &x);
            b[x] = i;
        }
        FOR(i,1,n)
        {
            FOR(j,1,n)
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
        printf("%d\n", f[n][n]);
    }
}
