/*
You can go the distance
You can run the mile
You can walk straight through hell with a smile

You can be the hero
You can get the gold
Breaking all the records they thought never could be broke

Yeah, do it for your people
Do it for your pride
How are you ever gonna know if you never even try?

Do it for your country
Do it for your name
'Cause there's gonna be a day...

When you're standing in the hall of fame
And the world's gonna know your name
'Cause you burn with the brightest flame

 -- "Hall Of Fame" --

 */

// Code by an idiot.

#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
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
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1
#ifdef ONLINE_JUDGE
#define printLL(x) printf("%I64d", x)
#else
#define printLL(x) cout << x
#endif

const int N = 1000;
const int oo = 1000000007;
int n;
II a[N];
vector<int> d[N], m[N];
bool mm[N], md[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("birthday.inp", "r", stdin);
   freopen("birthday.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &n);
    f1(i, n) {
        scii(a[i].F, a[i].S);
        d[a[i].F].pb(a[i].S);
        m[a[i].S].pb(a[i].F);
    }
    f1(month, 12) if (m[month].size() >= 2) {
            int cnt = 0;
            forit(it, m[month]) {
                if (d[*it].size() > 1) ++cnt;
            }
            if (cnt == 1) mm[month] = 1;
        }

    f1(day, 31) if (d[day].size() >= 2) {
            int cnt = 0;
            forit(it, d[day]) {
                if (m[*it].size() > 1) ++cnt;
            }
            if (cnt == d[day].size())
                md[day] = 1;
        }
    f1(i, n) if (md[a[i].F] && mm[a[i].S]) {
            printf("%d %d\n", a[i].F, a[i].S);
            break;
        }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}