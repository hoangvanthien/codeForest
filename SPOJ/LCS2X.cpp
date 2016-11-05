#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 1505
#define debug(x) cout<<#x<<" = "<<x<<endl
#define pb push_back
#define mp make_pair
#define pop pop_back
#define F first
#define S second
#define oo 2e9+7
#define II pair<int,int>
#define LL long long

int ans, a[maxN], b[maxN], f[maxN][maxN], d[maxN];
vector<int> temp;

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

void Trace(int i, int j)
{
    debug(i); debug(j);
    if (i == 0 || j == 0) return;
    if (a[i] == b[j])
    {
        int k = oo;
        if (temp.size() > 0) k = temp[temp.size()-1];
        if (2*a[i] <= k)
        {
            temp.pb(a[i]);
            if (ans < temp.size()) ans = temp.size();
            Trace(i-1, j-1);
            temp.pop();
            Trace(i-1, j-1);
        }
        else Trace(i-1,j-1);
    }
    else
    {
        if (f[i][j] == f[i-1][j]) Trace(i-1,j);
        if (f[i][j] == f[i][j-1]) Trace(i,j-1);
    }
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
    {
        ans = 0;
        int m,n;
        scanf("%d%d", &m, &n);
        FOR(i,1,m) scanf("%d", &a[i]);
        FOR(j,1,n) scanf("%d", &b[j]);
        //FOR(i,1,m) FOR(j,1,n) last[i][j] = oo;
        FOR(i,1,n) d[i] = 0;
        FOR(i,1,m)
        {
            int Max = 0;
            FOR(j,1,n)
            {
                if (a[i]==b[j])
                {
                    f[i][j] = Max + 1;
                }
                if (a[i] >= 2*b[j])
                {
                    Max = max(Max, d[j]);
                }
                if (a[i] == b[j])
                {
                    d[j] = max(f[i][j], d[j]);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        printf("%d\n", ans);
    }
}
