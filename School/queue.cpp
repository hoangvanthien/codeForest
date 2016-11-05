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
int n,a[N],b[N], sum;
bool rej[N];
vector<int> ans;
int main() {
	 freopen("queue.inp", "r", stdin);
	 freopen("queue.out", "w", stdout);
//	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	#endif // ONLINE_JUDGE
	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,1,n-1) scanf("%d", &b[i]);
    priority_queue<pair<int, II> > pq;
    FOR(i,1,n-1) pq.push(mp(a[i]+a[i+1]-b[i], mp(a[i]+a[i+1], -i)));
    while (pq.size()) {
        pair<int, II> fi = pq.top();
        pq.pop();
        if (fi.F <= 0) break;
        int i = -fi.S.S;
        if (rej[i] || rej[i+1]) continue;

//        ans.pb(i+1);
        sum += b[i];
        rej[i] = 1;
        rej[i+1] = 1;
    }
//    sort(ans.begin(), ans.end());
    FOR(i,1,n) if (!rej[i]) sum+=a[i];
    printf("%d\n", sum);
//    if (ans.size()) forit(it, ans) printf("%d ", *it);
//    else printf("0");
}

