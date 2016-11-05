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

int n,K,a[maxN][maxN],f[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &K);
    FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
}

void print()
{

}

int main()
{
	init();
	FOR(i,1,n)
	{
	    FOR(j,1,n)
	    {
	        f[i][j] = f[i-1][j] + a[i][j];
	        //printf("%d ", f[i][j]);
	    }
	    //printf("\n");
	}
	int ans = 0;
	FOR(i,1,n)
	{
        int j = i+K-1;
        {
            int k = 1, sum = 0;
            while (k <= K)
            {
                sum += f[j][k] - f[i-1][k++];
            }
            ans = max(ans, sum);
            while (k <= n)
            {
                sum += f[j][k] - f[i-1][k];
                sum -= f[j][k-K] - f[i-1][k-K];
                ans = max(ans, sum);
                k++;
            }
        }
	}
	printf("%d", ans);
}
