#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound

int a[maxN], n, s[maxN];
set<II> ans, temp;

int Find(int i, int len){
    len = min(len, n-i+1);
    int l = 1, r = len;
    int _res = -1;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (s[i+mid-1]-s[i-1]<0) {
            r = mid - 1;
            _res = mid;
        } else l = mid + 1;
        if (r == 0) _res = -1;
    }
    return i+_res-1;
}

bool ok(int len) {
    int i = 1;
    // deque<int> dq; dq.clear();
    temp.clear();
    while (i <= n) {

//        int sum = a[i], cnt = 1;
//        while (sum <= 0 && cnt < len) sum += a[i+1], ++i, ++cnt;
//        if (cnt == len && sum <= 0) return false;
//        while (a[i+1] < 0 && sum + a[i+1] > 0 && cnt < len) ++cnt, ++i;
        int Min = oo, cnt;
        // while (dq.size() > 1) dq.pop_front();
        // dq.push_back(dq.front() + 1); dq.pop_front();
        // while (!dq.empty() && s[j] - s[i-1] > 0 && s[dq.front()] - s[i-1] > s[j] - s[])
        FOR(j,i,i+len-1) if (s[j] - s[i-1] > 0 && Min >= s[j] - s[i-1]) {
            Min = s[j] - s[i-1];
            cnt = j-i+1;
        }
        if (Min == oo) return false;
        temp.insert(mp(i,cnt));
        i += cnt;
    }
    return true;
}

int main() {
	// freopen("rail.inp", "r", stdin);
	// freopen("rail.out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]), s[i] = s[i-1]+a[i];
//	printf("%d", getMonth(1,n));
	int l = 1, r = n, len = 0;
	while (l <= r) {
        int mid = (l+r) >> 1;
        if (ok(mid)) {
            r = mid-1;
            ans.clear();
            ans.insert(temp.begin(), temp.end());
            len = mid;
        } else l = mid+1;
	}
//	db(len);
	printf("%d %d\n", ans.size(), len);
	forit(it, ans) printf("%d ", (*it).S);
}
