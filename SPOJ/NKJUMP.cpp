/*
    github.com/hoangvanthien
    Thien Van Hoang
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

int n;
vector<int> dsk[maxN];
II a[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,1,n+1)
    {
        int x;
        scanf("%d", &x);
        a[i] = mp(x,i);
    }
    sort(a, a+n);
}

void LoadGraph()
{
    FOR(i,1,n+1)
    if (a[i].F != a[i-1].F)
    {
        b.pb(a[i].F);
        c[a[i].S] = a[i].S;
    }
    else c[a[i].S] = c[a[i-1].S];
    bool stop;
    for(int i = 0, i < b.size()-1 && !stop)
    FOR(j,i,b.size())
    {
        int k = upper_bound(b.begin()+j, b.end()+1, b[i]+b[j]) - b - 1;
        if (b[k] != b[i]+b[j])
    }
}

void DFS()
{
    memset(tt, 0, sizeof tt);
    vector<int> Stack;
    Stack.clear();

}

int main()
{
	init();
}
