#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 1000005
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n,m,a[maxN],b[maxN];
//map<II, int> f;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
}

int main()
{
	init();
	while (scanf("%d%d", &n, &m) && n!=0 && m!=0)
    {
        FOR(i,1,n) scanf("%d", &a[i]);
        FOR(j,1,m) scanf("%d", &b[j]);
        sort(b+1, b+1+m);
        int ans = 0;
        FOR(i,1,n)
        {
            int pos = lower_bound(b+1, b+1+m, a[i]) - b;
            if (pos != m+1)
                if (b[pos] == a[i]) ans ++;
        }
        printf("%d\n", ans);
    }
}
