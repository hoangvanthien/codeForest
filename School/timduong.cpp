#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 200002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

set<int> broke;
set<II> bridge;
int n, m;


bool direct(int u, int v)
{
	if (u == v) return true;
	if ((max(u,v) <= n && u<v) || (min(u,v) >= n+1 && u>v))
	{
		set<int>::iterator it = broke.lower_bound(u);
		if (it != broke.end())
			if (!(*it < v)) return true; else return false;
		else return false;
	}
	else return false;
}

void notify(bool content)
{
	if (content) puts("YES"); else puts("NO");
}

int main()
{
	freopen("timduong.inp", "r", stdin);
	//freopen("timduong.out", "w", stdout);
	scanf("%d%d", &n, &m);
	char event; int u,v;
	set<II>::iterator p1, p2;
	FOR(i,1,m)
	{
        scanf("%c", &event);
		scanf("%c %d %d", &event, &u, &v);
		//if (u>v) swap(u,v);
		switch (event)
		{
			case 'B': {broke.insert(max(u,v)-1); break;}
			case 'A': {bridge.insert(mp(u,v)); bridge.insert(mp(v,u)); break;}
			case 'Q':
			{
				if ((max(u,v) <= n && u<v) || (min(u,v) >= n+1 && u>v))
				{
					if (direct(u, v)) puts("YES"); else puts("NO");
					continue;
				}

				if ((max(u,v) <= n && u>v) || (min(u,v) >= n+1 && u<v))
				{
					p1 = bridge.lower_bound(mp(u,0));
					if (p1 == bridge.end()) notify(false);
					bool b1 = direct(u, ((*p1)).F);
					if (!b1) notify(false);
					int _u = (*p1).S;
					bool exist = false;
					while (_u >= n+1)
					{
						--_u;
						if (_u == n) break;
						p2 = bridge.lower_bound(mp(_u,0));
						if (p2 == bridge.end()) notify(false);
						if ((*p2).F != _u || (*p2).S > v) continue;
						bool b2 = direct(_u, (*p2).F);
						if (!b2) continue;
						bool b3 = direct((*p2).S, v);
						if (!b3) continue;
						notify(true);
						exist = true;
						break;
					}
					if (exist) continue;
					notify(false);

					// p2 = bridge.lower_bound(mp(v,0));
					// bool b1 = direct(u, (*p1).F);
					// bool b2 = direct(v, *v1.F);
					// if ((*p1).F == u && (*p2).F == v)
					// {
					// 	bool b1 = direct(u, (*p1).F);
					// 	bool b2 = direct(v, *v1.F);
					// 	if (b1 && b2) puts("YES"); else puts("NO");
					// }
					// else puts("NO");
					return 0;
				}

				p1 = bridge.lower_bound(mp(u,0));
				if (p1 == bridge.end()) notify(false);
				bool b1 = direct((*p1).S, v);
				if (b1) notify(true); else notify(false);
				continue;


			}
		}
	}

}
