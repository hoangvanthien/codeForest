#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define forrit(it, SS) for(__typeof(SS.rbegin()) it = SS.rbegin(); it!=SS.rend(); ++it)
//#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

multiset<int> sg, sb;
vector<int> vg,vb;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
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
        sg.clear();
        sb.clear();
        int k,ng,nb,x;
        scanf("%d%d%d", &k, &ng, &nb);
        FOR(i,1,ng)
        {
            scanf("%d", &x);
            sg.insert(x);
        }
        FOR(i,1,nb)
        {
            scanf("%d", &x);
            sb.insert(x);
        }
//        forit(it, sg) cout<<*it<<" ";
//            cout<<endl;
//            forit(it, sb) cout<<*it<<" ";
//            cout<<endl;
        while (!sg.empty() && !sb.empty())
        {
            vg.clear(); vb.clear();
            int n = min(k, (int)min(sg.size(), sb.size()));
            multiset<int>::iterator it;
            FOR(i,1,n)
            {
                it = sg.end(); --it;
                vg.pb(*it);
                //db(*it);
                sg.erase(it);
            }
            FOR(i,1,n)
            {
                it = sb.end(); --it;
                vb.pb(*it);
                //db(*it);
                sb.erase(it);
            }
//            forit(it, sg) cout<<*it<<" ";
//            cout<<endl;
//            forit(it, sb) cout<<*it<<" ";
//            cout<<endl;
            FOR(i,0,n-1)
            {
                if (vg[i] > vb[i]) sg.insert(vg[i]-vb[i]);
                if (vg[i] < vb[i]) sb.insert(vb[i]-vg[i]);
            }
//            forit(it, sg) cout<<*it<<" ";
//            cout<<endl;
//            forit(it, sb) cout<<*it<<" ";
//            cout<<endl;
        }
        if (sg.empty() && sb.empty()) puts("green and blue died");
        else
            if (sg.empty())
            {
                puts("blue wins");
                forrit(it, sb) printf("%d\n", *it);
            }
            else
                if (sb.empty())
                {
                    puts("green wins");
                    forrit(it, sg) printf("%d\n", *it);
                }
        if (T) cout<<endl;
    }
}
