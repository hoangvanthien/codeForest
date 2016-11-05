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
int a[N];
template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
int findPivot(int i, int j) {
    int firstKey = a[i];
    FOR(k,i+1,j) if (a[k] != firstKey) return min(firstKey, a[k]);
    return oo;
}
int partition(int i, int j, int pivot) {
    int l = i, r = j;
    while (l<=r) {
        while (a[l] <= pivot) ++l;
        while (a[r] > pivot) --r;
        if (l<r) swap(a[l], a[r]);
    }
    return l;
}
void quickSort(int i, int j) {
    int pivot = findPivot(i,j);
    if (pivot != oo) {
        int k = partition(i,j,pivot);
        quickSort(i,k-1);
        quickSort(k,j);
    }
}
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int n; cin >> n;
	FOR(i,1,n) cin >> a[i];
    quickSort(1,n);
    FOR(i,1,n) cout << a[i] << " ";
}
