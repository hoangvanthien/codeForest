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

int n;
LL a[maxN], Min[maxN], Max[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    FOR(i,1,n) scanf("%lld", &a[i]);
}

void print()
{

}

int main()
{
	init();
	Max[n] = Min[n] = a[n];
	DFOR(i,n-1,1)
	{
	    Max[i] = max(a[i], max(Max[i+1], a[i] - Min[i+1]));
	    Min[i] = min(a[i], min(Min[i+1], a[i] - Max[i+1]));
	}
	printf("%lld", Max[1]);
}
