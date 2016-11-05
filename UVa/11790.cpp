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

int T, h[maxN], w[maxN], giam[maxN], tang[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
}

void print()
{

}

int main()
{
	init();
	scanf("%d", &T);
	FOR(__T, 1, T)
    {
        int n;
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &h[i]);
        FOR(i,1,n) scanf("%d", &w[i]);
        FOR(i,1,n) tang[i] = giam[i] = w[i];
        DFOR(i,n,1)
        {
            FOR(j,i+1,n)
            {
                if (h[j] > h[i]) tang[i] = max(tang[i], w[i]+tang[j]);
                if (h[j] < h[i]) giam[i] = max(giam[i], w[i]+giam[j]);
            }
        }
        int inc = *max_element(tang+1, tang+1+n), dec = *max_element(giam+1, giam+1+n);
        if (inc >= dec)
        {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", __T, inc, dec);
        }
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", __T, dec, inc);
    }
}
