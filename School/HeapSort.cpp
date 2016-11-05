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

const int N = 100002;
const int oo = 1000000007;
int n, a[N];
template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
void pushDown(int node, int i, int j) {
    if (node > j/2) return;
    if (j == 2*node) {
        if (a[node] > a[node*2]) {
            swap(a[node], a[node*2]);
            return;
        }
    } else {
        if (a[node] > a[node*2] && a[node*2] <= a[node*2+1]) {
            swap(a[node], a[node*2]);
            pushDown(node*2, i, j);
        } else
        if (a[node] > a[node*2+1] & a[node*2+1]<a[node*2]) {
            swap(a[node], a[node*2+1]);
            pushDown(node*2+1, i, j);
        } else return;
    }
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	cin >> n;
	FOR(i,1,n) cin >> a[i];
    DFOR(i,n/2,1) pushDown(i,i,n);
    DFOR(i,n,2) {
        swap(a[1], a[i]);
        pushDown(1,1,i-1);
    }
    FOR(i,1,n) cout << a[i] << " ";
}

