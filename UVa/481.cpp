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

int a[maxN], lis[maxN], lis_id[maxN], trace[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
}

void print_lis(int i)
{
    if (i == -1) return;
    print_lis(trace[i]);
    printf("%d\n", a[i]);
}

int main()
{
	init();
	int l = 0;
	for(int i = 0; ;++i)
    {
        if (scanf("%d", &a[i]) == EOF) break;
        int pos = lower_bound(lis, lis+l, a[i]) - lis;
        lis[pos] = a[i];
        lis_id[pos] = i;
        trace[i] = (pos > 0) ? lis_id[pos-1] : -1;
        if (l==pos) ++l;
    }
    printf("%d\n-\n", l);
    print_lis(lis_id[l-1]);
}
