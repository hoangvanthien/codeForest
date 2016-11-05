#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

queue<int> ql, qr;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    //std::ios::sync_with_stdio(false);
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
		int l,m;
		scanf("%d%d", &l, &m);
		ql = queue<int>();
		qr = queue<int>();
		l*=100;
		FOR(i,1,m)
		{
			int x; char tmp[6];
			scanf("%d %s", &x, tmp);
			if (tmp[0] == 'l')
            {
                ql.push(x);
                }else qr.push(x);
		}


		int cnt = ql.size() + qr.size();
		int ans = 0;
		while (cnt > 0)
		{
			int len = l;
			while (len >= ql.front() && !ql.empty())
			{
				len -= ql.front();
				//db(ql.front());
				--cnt;
				ql.pop();
				if (ql.empty()) break;
			}

			++ans;
			if (cnt == 0) break;
			len = l;
			//db(qr.front());
			while (len >= qr.front() && !qr.empty())
			{
				len -= qr.front();
				--cnt;
				qr.pop();
				if (qr.empty()) break;
			}
			++ans;
		}
		printf("%d\n", ans);
	}
}
