// Accepted Solution

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


int T, a[maxN],n, tang[maxN], giam[maxN];

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
	FOR(___i, 1, T)
	{
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        int Ans = 0;
        FOR(i,1,n+1) tang[i] = giam[i] = 0;
        a[n+1] = oo;
        DFOR(i,n,1)
        {
            int _max = 0, jmax = n+1;
            FOR(j,i+1,n+1)
            if (tang[j] > _max && a[i] < a[j])
            {
                _max = tang[j];
                jmax = j;
            }
            tang[i] = tang[jmax] + 1;
        }
        a[n+1] = 0;
        DFOR(i,n,1)
        {
            int _max = 0, jmax = n+1;
            FOR(j,i+1,n+1)
            if (giam[j] > _max && a[i] > a[j])
            {
                _max = giam[j];
                jmax = j;
            }
            giam[i] = giam[jmax] + 1;
        }
        FOR(i,1,n) Ans = max(Ans, tang[i] + giam[i] - 1);
        printf("%d\n", Ans);
	}
}
