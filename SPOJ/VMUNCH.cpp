#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define II pair<int,int>
#define mp make_pair
#define F first
#define S second

II start,finish;
int m,n;

void init()
{
    freopen("VMUNCH.INP", "r", stdin);
    freopen("VMUNCH.OUT", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i,1,m)
    FOR(j,1,n+1)
    {
        char c;
        scanf("%c", &c);
        if (c=='B') start = mp(i,j);
        if (c=='C') finish = mp(i,j);
    }
}

int main()
{
    init();
    printf("%d",abs(start.F - finish.F)+abs(start.S - finish.S));
}
