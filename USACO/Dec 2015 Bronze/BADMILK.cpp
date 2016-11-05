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

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
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
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)

const int N = 52;
const int oo = 1000000007;
int n, m, D, S, boo[N][N], die[N], toxic[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d%d%d", &n, &m, &D, &S);
    int person, milk, time;
    FOR(i, 1, m) FOR(j, 1, n) boo[i][j] = oo;
    FOR(i,1,n) die[i] = oo;
    FOR(i, 1, D) {
        scanf("%d%d%d", &person, &milk, &time);
        minimize(boo[milk][person], time);
    }
    FOR(i, 1, S) {
        scanf("%d%d", &person, &time);
        die[person] = time;
    }
    FOR(i, 1, m) toxic[i] = true;
    FOR(i, 1, m) {
        FOR(j, 1, n) {
//            if (die[j] != 0 && boo[i][j] == oo) {
//
//                toxic[i] = false;
//                break;
//
//            }
            if (die[j] != 0 && die[j] < boo[i][j]) {
                toxic[i] = false;
                break;
            }
        }
    }
//    FOR(i,1,m) printf("%d ", toxic[i]);
//    nl;
    int ans = 0;
    FOR(i, 1, m) if (toxic[i]) {
            int cnt = 0;
            FOR(j, 1, n) if (die[j] != 0 && boo[i][j] < die[j]) ++cnt;
            maximize(ans, cnt);
        }
    printf("%d\n", ans);

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}