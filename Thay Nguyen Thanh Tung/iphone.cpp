// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scni(i) int i; scanf("%d",&i)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)
#define scniiii(a, b, c, d) int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1

const int N = 200005;
const int oo = 1000000007;


int main() {
#ifndef ONLINE_JUDGE
    freopen("iphone.inp", "r", stdin);
    freopen("iphone.out", "w", stdout);
#endif // ONLINE_JUDGE
    int n, k;
    while (cin >> n >> k) {
//        set<int> s;
//        f0(a, k + 1) {
//        cout << a << ' ' << k - a << '\n';
//            int temp = a * 2 - k;
//            while (temp < 0) temp += n;
//            s.insert(temp % n);
//        }
//        forit(it, s) printf("%d ", *it);
//        nl;
//        cout << s.size() << '\n';
        if (n % 2 == 0) {
            if (n > k * 2 + 1) cout << k + 1;
            else cout << n / 2;
        } else {
            if (n > k) cout << k + 1;
            else cout << n;
        }
    }
//    if (n > k * 2 + 1) cout << k + 1;
//    else if (n % 2 == 0) cout << n / 2;
//    else cout << n;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}