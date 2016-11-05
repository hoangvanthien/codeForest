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

const int N = 1000002;
const int oo = 1000000007;

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
int a[N], lis[N], lis_id[N], trace[N];
int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	int T; cin >> T;
	getchar();
	getchar();
	while (T--) {
        char s[100];
        int l = 0;
        for(int i=0; ; ++i) {
            if (!gets(s)) break;
            if (s[0] == '\0') break;
            sscanf(s, "%d", &a[i]);
//            int temp = s.size();
//            cout << s << endl;
//            stringstream ss;
//            ss.str(s);
//            ss >> a[i];
            int pos = lower_bound(lis, lis+l, a[i]) - lis;
            lis[pos] = a[i];
            lis_id[pos] = i;
            trace[i] = pos > 0 ? lis_id[pos-1] : -1;
            if (pos==l) ++l;
        }
        printf("Max hits: %d\n", l);
        int x = lis_id[l-1];
        vector<int> ans; ans.clear();
        while (x!=-1) {
            ans.pb(a[x]);
            x = trace[x];
        }
        forrit(it, ans) printf("%d\n", *it);
        if (T) puts("");
	}
}
