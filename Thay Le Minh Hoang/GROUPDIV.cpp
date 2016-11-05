#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 300002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define show(x) { cout<<#x<<" "; forit(it, x) printf("%d(%d) ", (*it).S, -(*it).F); printf("\n"); }

int conflict[maxN], n, cur[maxN];
std::vector<int> dsk[maxN];
queue<int> q;
bool tt[maxN];

void init() {
	freopen("groupdiv.inp", "r", stdin);
	freopen("groupdiv.out", "w", stdout);
    // #ifndef ONLINE_JUDGE
    //     freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
    // #endif // ONLINE_JUDGE
    scanf("%d", &n);
    FOR(i,1,n) {
    	int x,y; scanf("%d", &x);
    	conflict[i] = x;
    	FOR(j,1,x) {
    		scanf("%d", &y);
    		dsk[i].pb(y);
    	}
    	if (x >= 2) q.push(i), tt[i] = true;
    	cur[i] = 1;
    }
    //show(group[1]);
}

int main() {
	init();
	while (!q.empty()) {
        while (!q.empty() && conflict[q.front()] <= 1) {tt[q.front()] = 0; q.pop();}
        if (q.empty()) break;
        int u = q.front(); q.pop(); tt[u] = 0;
        cur[u] = 3-cur[u];
        FOR(i,0,(int)dsk[u].size()-1) {
            int v = dsk[u][i];
            if (cur[v] == cur[u]) {
                ++conflict[u], ++conflict[v];
                if (conflict[v] >= 2 && !tt[v]) {q.push(v); tt[v] = 1;}
            }
            else --conflict[u], --conflict[v];
        }
	}
	puts("YES");
	FOR(k,1,2) {
        FOR(i,1,n) if (cur[i] == k) printf("%d ", i);
        printf("\n");
	}
}

