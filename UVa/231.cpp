#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 1000002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int f[maxN];
vector<int> a;

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
	int T = 0, x;
	while (scanf("%d", &x) && (x!=-1))
    {
        if (T) printf("\n");
        a.clear();
        a.pb(x);
        while (scanf("%d", &x) && x!=-1) a.pb(x);
        int n = a.size();
        FOR(i,0,n-1) f[i] = 1;
        DFOR(i,n-1,0)
        {
            FOR(j,i+1,n-1)
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
        int ans = *max_element(f,f+n);
        printf("Test #%d:\n", ++T);
        printf("  maximum possible interceptions: %d\n", ans);
    }
}
