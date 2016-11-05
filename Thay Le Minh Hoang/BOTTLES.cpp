#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 1000002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int a[maxN], n, k, trace[maxN];
LL f[maxN], sum;
bool select[maxN];
deque<int> dq;

void init() {
	 freopen("bottles.inp", "r", stdin);
	 freopen("bottles.out", "w", stdout);
	 ios::sync_with_stdio(false);
//    #ifndef ONLINE_JUDGE
//        freopen("F:\\CppProjects\\TemporarilyProject\\input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i], sum += a[i];
//    FOR(i,1,n+1) f[i] = 0;
}

int main() {
	init();
	dq.pb(0);
	FOR(i,1,n+1) {
        while (!dq.empty() && f[dq.back()] >= f[i-1])
            dq.pop_back();
        dq.pb(i-1);
        while (!dq.empty() && i - dq.front() > k) dq.pop_front();
        f[i] = f[dq.front()] + (LL)a[i];
        trace[i] = dq.front();
	}
	int x = trace[n+1], cnt = 0;
	LL temp_sum = 0;
	while (x!=0) {
        select[x] = true; ++cnt; temp_sum += (LL)a[x];
        x = trace[x];
	}
	cout << n - cnt << " " << sum - temp_sum << endl;
	FOR(i,1,n) if (!select[i]) cout << i << " ";
}
