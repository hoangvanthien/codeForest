// AC
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

int Time[maxN], ans[maxN];
queue<int> q[2];

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
}

void print()
{

}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n,t,m,x;
		scanf("%d%d%d", &n, &t, &m);
		char tmp[6];
		FOR(i,1,m)
		{
			scanf("%d %s", &x, tmp);
			Time[i] = x;
			if (tmp[0] == 'l') q[0].push(i); else q[1].push(i);
		}
		int curTime = 0, curSide = 0;
		while (!q[0].empty() || !q[1].empty())
		{
			int minTime;
			if (!q[0].empty() && !q[1].empty()) minTime = min(Time[q[0].front()], Time[q[1].front()]);
			else
				if (!q[0].empty()) minTime = Time[q[0].front()];
				else minTime = Time[q[1].front()];
			curTime = max(curTime, minTime);
			int cnt = 0;
			while (!q[curSide].empty() && cnt < n && Time[q[curSide].front()] <= curTime)
			{
				++cnt;
				ans[q[curSide].front()] = curTime+t;
				q[curSide].pop();
			}
			curTime += t;
			curSide = 1 - curSide;
		}
		FOR(i,1,m) printf("%d\n", ans[i]);
		if (T) printf("\n");
	}
}
