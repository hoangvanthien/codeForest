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
#define ld long double
#define renew(x) memset(x, 0, sizeof x)

const int N = 100002;
const int oo = 1000000007;
int a[N], f[N], start[N], T[N*4], n, m;
map<int, int> val;
template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
void initTree(int node, int l, int r) {
    if (l > r) return;
    if (l==r) {
        T[node] = f[l];
        return;
    }
    int mid = (l+r)/2;
    initTree(node*2, l, mid);
    initTree(node*2+1, mid+1, r);
    T[node] = max(T[node*2], T[node*2+1]);
}
int getMax(int node, int l, int r, int i, int j) {
    if (i > j) return -1;
    if (i > r || j < l) return -1;
    if (i <= l && r <= j) return T[node];
    int mid = (l+r)/2;
    int res = getMax(node*2, l, mid, i, j);
    maximize(res, getMax(node*2+1, mid+1, r, i, j));
    return res;
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	while (scanf("%d", &n) && n!=0) {
        scanf("%d", &m);
        val.clear();
        renew(T); renew(f); renew(start);
        FOR(i,1,n) scanf("%d", &a[i]), val[a[i]]++;
        FOR(i,1,n) f[i] = val[a[i]], start[i] = a[i] == a[i-1] && i != 1 ? start[i-1] : i;
        initTree(1,1,n);
        FOR(i,1,m) {
            int x, y; scanf("%d%d", &x, &y);
            if (a[x] == a[y]) {
                printf("%d\n", y-x+1);
                continue;
            }
            int cnt1 = start[x]+f[x]-x;
            int cnt2 = y-start[y]+1;
            x = start[x]+f[x];
            y = start[y]-1;
            int cnt3 = getMax(1,1,n,x,y);
            printf("%d\n", max(max(cnt1,cnt2),cnt3));
        }
	}
}

