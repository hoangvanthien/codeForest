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
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 100002;
int n, a[N], b[N], id1[N], id2[N];

int main() {


        freopen("F:\\CppProjects\\Tests\\20.in", "r", stdin);
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]), id1[a[i]] = i;
        FOR(i,1,n) scanf("%d", &b[i]), id2[b[i]] = i;
        vector<II> ans;
        FOR(i,1,n) FOR(j,1,n) if (i!=j && id1[i] < id1[j] && id2[i] < id2[j]) ans.pb(mp(i,j));
        freopen("F:\\\CppProjects\\\Tests\\20.in", "w", stdout);
        printf("%d %d\n", n, ans.size());
        forit(it, ans) printf("%d %d\n", it->F, it->S);

}
