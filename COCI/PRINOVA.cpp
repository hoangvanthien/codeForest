/*
    github.com/hoangvanthien
    Thien Van Hoang
    Accepted Solution
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN],n,A,B;
int b[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,0,n) scanf("%d", &a[i]);
    sort(a, a+n);
    scanf("%d%d", &A, &B);
    if (A%2 == 0) A--;
    if (B%2 == 0) B--;
    FOR(i,0,n-1)
    {
        b[i] = (a[i]+a[i+1])/2;
        if (b[i]%2 == 0)
            if (++b[i]>B) b[i]-=2;
    }
}

void print()
{

}

int main()
{
	init();
	int ans = A;
	int d = 0;
	FOR(i,0,n-1)
	if (A<=b[i] && b[i]<=B)
	{
	    int _d = min(abs(b[i]-a[i]), abs(b[i]-a[i+1]));
	    if (_d>d)
        {
            d = _d;
            ans = b[i];
        }
	}

    int pA = lower_bound(a, a+n, A) - a, dA;
    if (pA == 0) dA = abs(A - a[pA]);
    else
        if (pA != n) dA = min(abs(A - a[pA]), abs(A - a[pA-1]));
        else dA = abs(A-a[pA-1]);

    int pB = lower_bound(a, a+n, B) - a, dB;
	if (pB == 0) dB = abs(B - a[pB]);
	else
        if (pB != n) dB = min(abs(B - a[pB]), abs(B - a[pB-1]));
        else dB = abs(B-a[pB-1]);

    int Max = max(d, max(dA, dB));
    if (Max == d) printf("%d", ans);
    else if (Max == dA) printf("%d", A);
    else if (Max == dB) printf("%d", B);

}
