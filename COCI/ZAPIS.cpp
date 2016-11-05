/*
    github.com/hoangvanthien
    Thien Van Hoang
    Accepted Solution
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 1001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define mod 100000LL

char s[201];
char *o = "([{";
char *c = ")]}";
LL d[maxN][maxN];
int n;

LL MOD(LL a)
{
    if (a>=mod) return mod + a%mod; else return a;
}

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    scanf("%s", s);
    memset(d, -1, sizeof d);
}

void print()
{

}

int Cal(int left, int right)
{
    if (right < left) return 1;

    LL &ans = d[left][right];
    if (ans >= 0) return ans;

    ans = 0;
    for (int i=left+1; i<=right; i+=2)
        FOR(j,0,3)
        if ((s[left] == o[j] || s[left] == '?') && (s[i] == c[j] || s[i] == '?'))
            ans = MOD(ans + Cal(left+1, i-1)*Cal(i+1, right));

    return ans;
}

int main()
{
	init();
	LL res = Cal(0,n-1);
    if (res >= mod) printf("%05lld", res - mod); else printf("%lld", res);
}

