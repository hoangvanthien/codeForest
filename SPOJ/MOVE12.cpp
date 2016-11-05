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
#define II pair<long long, long long>
#define LL long long

int c[maxN], t[maxN], n;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,0,n)
    {
        scanf("%d%d", &c[i], &t[i]);
        c[i] --;
    }
}

void print()
{

}

bool possible(LL time)
{
    multiset< II > s;
    FOR(i,0,n)
    {
        LL right = min((LL)n-1, (LL)c[i]+time/t[i]);
        LL left = max((LL)0, (LL)c[i]-time/t[i]);
        s.insert(mp(right, left));
    }

    FOR(i,0,n)
    {
        bool found = false;
        for (multiset<II>::iterator it = s.begin(); it!=s.end(); ++it)
        {
            II bound = *it;
            if (bound.F < i) return false;
            if (bound.S <= i && i <= bound.F)
            {
                s.erase(it);
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main()
{
    init();
    LL l = 0, r = *max_element(t, t+n) * n, ans;
    while (l<=r)
    {
        LL mid = (l+r)/2;
        if (possible(mid))
        {
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << ans;
}
