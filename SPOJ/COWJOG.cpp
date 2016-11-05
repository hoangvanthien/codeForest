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
int a[N], v[N];
vector<LL> lis;

int main() {


    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);




    int n,t; scanf("%d%d", &n, &t);
    FOR(i,1,n) {
        int x,y; scanf("%d%d", &x, &y);
        LL ai = -(LL)x -(LL)y*t;
        vector<LL>::iterator it = ub(lis.begin(), lis.end(), ai);
        if (it == lis.end()) lis.pb(ai);
        else *it = ai;
    }
    cout << lis.size();

}
