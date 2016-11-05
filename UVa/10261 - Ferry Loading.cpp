#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 10002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long


int f[maxN][maxN], len;
int a[maxN], sum[maxN];
vector<int> ans;
bool port[maxN];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
    {
        scanf("%d", &len); len*=100;
        int x, n = 0;
        while (scanf("%d", &x) && x!=0)
        {
            a[++n] = x;
            sum[n] = sum[n-1]+x;
        }
        FOR(i,1,n) FOR(L1,0,len) f[i][L1] = 0;
        f[0][len] = 1;
        int i = 1;
        for(; i<=n; ++i)
        {
            bool ok = false;
            FOR(L1, 0, len)
            if (f[i-1][L1] != 0)
            {
                int L2 = 2*len - L1 - sum[i-1];
                if (a[i] <= L1) f[i][L1-a[i]] = 1, ok = true;
                if (a[i] <= L2) f[i][L1] = 2, ok = true;
            }
            if (!ok) break;
        }
        --i;
        int L1;
        FOR(j,0,len)
        if (f[i][j] != 0) L1 = j;
        ans.clear();
        while (i!=0)
        {
            ans.pb(f[i][L1]);
            if (ans.back() == 1) L1+=a[i];
            --i;
        }
        printf("%d\n", ans.size());
        DFOR(j, ans.size()-1, 0)
        if (ans[j] == 1) puts("port"); else puts("starboard");

        if (T) printf("\n");
    }
}
