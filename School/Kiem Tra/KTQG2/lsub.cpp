#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1000002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n, a[maxN];
map<int, int> m;

void init()
{
    freopen("lsub.inp", "r", stdin);
    freopen("lsub.out", "w", stdout);
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
}

void print()
{

}

int main()
{
	init();
	int l = 1, r = 2, temp = 1, Max = 0;
	m[a[1]] = 1;
	while (r<=n)
	{
		if (l<=m[a[r]] && m[a[r]]<=r)
		{
			Max = max(Max, temp);
			temp = r-m[a[r]];
			l = m[a[r]] + 1;
			m[a[r]] = r;
		}
		else
		{
			m[a[r]] = r;
			++temp;
		}
		++r;
	}
	Max = max(Max, temp);
	printf("%d", Max);
}

