#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

vector<int> temp;
vector< pair< pair<int,int> , int> > blocks;
int f[maxN];

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
    int n = 1, T = 0;
    while (true)
    {
        scanf("%d", &n);
        if (n==0) exit(0);
        blocks.clear();
        FOR(i,1,n)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            temp.clear();
            temp.pb(x); temp.pb(y); temp.pb(z);
            sort(temp.begin(), temp.end());
            x = temp[0]; y = temp[1]; z = temp[2];
            blocks.pb(mp(mp(x,y), z));
            blocks.pb(mp(mp(x,z), y));
            blocks.pb(mp(mp(y,z), x));
        }
        sort(blocks.begin(), blocks.end());
        int N = blocks.size();
        DFOR(i,N-1,0)
        {
            f[i] = blocks[i].S;
            FOR(j,i+1,N-1)
            if (blocks[j].F.F > blocks[i].F.F && blocks[j].F.S > blocks[i].F.S)
                f[i] = max(f[i], f[j] + blocks[i].S);
        }
        int ans = *max_element(f, f+N);
        printf("Case %d: maximum height = %d\n", ++T, ans);
    }
}
