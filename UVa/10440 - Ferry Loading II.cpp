#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

vector<int> q;
int n,t,m;

int MinTime(int curr, int s, int f)
{
    if (f<s) return curr;
    int ind = s-1;
    FOR(i,1,(f-s+1)/n)
    {
        ind += n;
        curr = max(curr, q[ind]);
        curr += 2*t;
    }
    return curr;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int ind=0;
		q.clear();
		scanf("%d%d%d", &n, &t, &m);
		FOR(i,1,m)
		{
			int x; scanf("%d", &x);
			q.pb(x);
		}
		int curTime = 0;
		if (m%n==0)
        {
            ind = -1;
            FOR(i,1,m/n)
            {
                ind += n;
                curTime = max(curTime, q[ind]);
                curTime += 2*t;
            }
            printf("%d %d\n", curTime-t, m/n);
        }
        else
        {
            int ans = oo;
            FOR(i,0,(m-1)/n)
            {
                curTime = 0;
                curTime = MinTime(curTime, 0, i*n-1);
                curTime = max(curTime, q[i*n-1+m%n]);
                curTime += 2*t;
                curTime = MinTime(curTime, i*n+m%n, m-1);
                ans = min(ans, curTime);
            }
            printf("%d %d\n", ans-t, m/n+1);
        }
	}
}
