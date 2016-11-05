#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define maxN 1000002
#define pb push_back

int n, k, a[maxN], Min;
deque<int> dq;
int main() {
    freopen("MINIMUM.inp", "r", stdin);
    freopen("MINIMUM.out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i,1,n) scanf("%d", &a[i]);
    FOR(i,1,n) {
    	while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
    	dq.pb(i);
    	while (i - dq.front() >= k) dq.pop_front();
    	if (i >= k) printf("%d\n", a[dq.front()]);
    }
}
