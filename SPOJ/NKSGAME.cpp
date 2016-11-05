#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo (1e9)*2 + 7
#define II pair<int,int>
#define LL long long

int n, a[maxN], b[maxN];
int ans;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("INPUT.INP", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,0,n) scanf("%d", &a[i]);
    FOR(i,0,n) scanf("%d", &b[i]);
    sort(a,a+n);
    sort(b,b+n);
    ans = oo;
}

void print()
{
    printf("%d", ans);
}

int main()
{
    init();
    FOR(i,0,n)
    {
        int b1 = oo,b2 = oo;
        int pos = lower_bound(b,b+n,-a[i]) - b;

        if (pos == n) b2 = abs(a[i] + b[n-1]);
        else b2 = abs(a[i] + b[pos]);

        if (pos>0) b1 = abs(a[i]+ b[pos-1]);

        ans = min(ans, min(b1, b2));
        if (ans==0) break;
    }
    print();
}
