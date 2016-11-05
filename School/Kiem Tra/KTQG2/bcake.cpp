#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 505
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN][maxN], f[maxN][maxN], m, n, k;

void init()
{
    freopen("bcake.inp", "r", stdin);
    freopen("bcake.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    FOR(i,1,m) FOR(j,1,n)
    {
    	int x;
    	scanf("%d", &x);
    	if (x>=k) a[i][j] = 1; else a[i][j] = 0;
    }

}

int main()
{
	init();
	FOR(i,1,m) FOR(j,1,n) f[i][j] = f[i-1][j] + a[i][j];
	int Max = 0;
	FOR(i,1,m) FOR(j,i,m)
	{
		int k = 1;
		while (k<=n)
		{
			int temp = 0;
			while (k<=n && f[j][k]-f[i-1][k] == j-i+1) {++k; ++temp;}
			Max = max(Max, temp*(j-i+1));
			++k;
		}
	}
	printf("%d", Max);
}

