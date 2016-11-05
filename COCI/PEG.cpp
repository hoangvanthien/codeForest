/*
    Thien Van Hoang
    Accepted Solution
    http://wcipeg.com/problem/coci071p2
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>(y); --i)
#define maxN 101
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

string s[maxN];
int a[maxN][maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    FOR(i,0,7) getline(cin, s[i]);
    FOR(i,0,10)
    FOR(j,0,10) a[i][j] = -1;
    FOR(i,0,7)
    FOR(j,0,s[i].size())
    switch (s[i][j])
    {
        case '.': a[i][j] = 0; break;
        case 'o': a[i][j] = 1; break;
    }
}

void print()
{

}

bool possible(int x, int y, int dx, int dy)
{
    if (!(0<=x+2*dx && 0<=y+2*dy)) return false;
    if (a[x+dx][y+dy] == 1 && a[x+2*dx][y+2*dy] == 0) return true;
    return false;
}

int main()
{
    init();
    int ans = 0;
    FOR(i,0,7)
    FOR(j,0,7)
    if (a[i][j] == 1)
    {
        ans += possible(i,j, -1, 0);
        ans += possible(i,j, +1, 0);
        ans += possible(i,j, 0, -1);
        ans += possible(i,j, 0, +1);
    }
    printf("%d", ans);
}
