#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 1000002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int cnt[maxN];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
}

int main()
{
	init();
	int n;
	LL ans = 0;
	set<int> s;
	while (scanf("%d", &n) && n!=0)
    {
        ans = 0;
        s.clear();
        memset(cnt, 0, sizeof cnt);
        FOR(i,1,n)
        {
            int k;
            scanf("%d", &k);
            FOR(j,1,k)
            {
                int x;
                scanf("%d", &x);
                cnt[x] ++;
                s.insert(x);
            }
            int Max = *(--s.end()), Min = *(s.begin());
            ans += (LL)(Max) - (LL)(Min);
            cnt[Max]--;
            cnt[Min]--;
            if (cnt[Max] == 0) s.erase(--s.end());
            if (cnt[Min] == 0) s.erase(s.begin());

        }
        printf("%lld\n", ans);
    }
}
