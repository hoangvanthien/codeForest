
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 100002;
const int oo = 1000000007;
vector<II> seg, ans;
int M;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int T; scanf("%d", &T);
	while (T--) {
        scanf("%d", &M);
        seg.clear(); ans.clear();
        int x,y; while (scanf("%d%d", &x, &y) && !(x==0 && y==0)) seg.pb(mp(x,y));
        sort(seg.begin(), seg.end());
        int l = 0, r = 0, i = 0;
        while (r < M) {
            int imax = -1, maxR = l;
            for (; i<seg.size(); ++i) {
                if (seg[i].F > l) break;
                if (maxR <= seg[i].S) {
                    imax = i;
                    maxR = seg[i].S;
                }
            }
            if (imax != -1) {
                r = l = maxR;
                ans.pb(seg[imax]);
            } else break;
        }
        if (r >= M) {
            printf("%d\n", ans.size());
            forit(it, ans) printf("%d %d\n", it->F, it->S);
        } else puts("0");
        if (T) puts("");
	}
}
