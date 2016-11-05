#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int f[maxN];

void init()
{
    freopen("biendoi.inp", "r", stdin);
    freopen("biendoi.out", "w", stdout);
    std::ios::sync_with_stdio(false);
}

int dp(int k)
{
    if (k==1) return f[k] = 0;
    if (f[k]!=0) return f[k];
    int t1=oo,t2=oo,t3=oo;
    if (k%2 == 0) t1 = dp(k/2);
    if (k%3 == 0) t2 = dp(k/3);
    if (k>1) t3 = dp(k-1);
    return (f[k] = 1+min(t1,min(t2,t3)));
}

int main()
{
	init();
	int T, n;
	scanf("%d", &T);
	while (T--)
    {
        scanf("%d", &n);
        FOR(i,1,n) f[i] = 0;
        printf("%d\n", dp(n));
    }
}
