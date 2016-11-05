/*
    github.com/hoangvanthien
    Thien Van Hoang
    Accepted Solution
    http://wcipeg.com/problem/coci071p1
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

II p[5], v[5][5];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    FOR(i,1,4) scanf("%d%d", &p[i].F, &p[i].S);
    FOR(i,1,4)
    FOR(j,1,4)
    if (i!=j) v[i][j] = mp(p[j].F - p[i].F, p[j].S - p[i].S);
}

void print()
{

}

int main()
{
    init();
    int goc;
    FOR(i,1,4)
    {
        FOR(j,1,4)
        if (i!=j)
        {
            if (v[i][j].F * v[i][6-i-j].F + v[i][j].S * v[i][6-i-j].S == 0)
            {
                goc = i;
                int xi = p[j].F + p[6-i-j].F;
                int yi = p[j].S + p[6-i-j].S;
                printf("%d %d", xi-p[goc].F, yi-p[goc].S);
                exit(0);
            }
        }
    }
}
