/*
    github.com/hoangvanthien
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

int k, n, a[maxN], b[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE


}

void print()
{

}

bool possible(int position)
{
    FOR(i,0,position+1) b[i] = a[i];
    sort(b, b+position+1);
    int s = 0;
    FOR(i,0,position+1)
    {
        if (b[i] > s+1) return false;
        s = s+b[i];
        if (s>=k) return true;
    }
    if (s>=k) return true; else return false;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    FOR(i,0,T)
    {
        scanf("%d%d", &n, &k);
        FOR(j,0,n) scanf("%d", &a[j]);
        //sort(a, a+n);
        int l = 0, r = n-1, ans = -2;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (possible(mid))
            {
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        printf("%d\n", ans+1);
    }
}
