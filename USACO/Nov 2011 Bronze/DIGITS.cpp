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

const int N = 100002;
const int oo = 1000000007;
char T[N];
int a[N], b[N], lt2[N], lt3[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int A = 0, B = 0;
    scanf("%s", T);
    int m = (int) strlen(T);
    reverse(T, T + strlen(T));
    REP(i, m) {
        a[i] = T[i] - '0';
        lt2[i] = i == 0 ? 1 : lt2[i - 1] * 2;
        A += lt2[i] * a[i];
    }

    scanf("%s", T);
    int n = (int) strlen(T);
    reverse(T, T + strlen(T));
    REP(i, n) {
        b[i] = T[i] - '0';
        lt3[i] = i == 0 ? 1 : lt3[i - 1] * 3;
        B += lt3[i] * b[i];
    }
    REP(i, m) REP(j, n) {
            II init = mp(a[i], b[j]);
            II INIT = mp(A, B);
            A -= a[i] * lt2[i];
            B -= b[j] * lt3[j];
            FOR(x, 0, 1) if (x != init.first) {
                    FOR(y, 0, 2) if (y != init.second) {
                            a[i] = x;
                            b[j] = y;
                            if (A + a[i] * lt2[i] == B + b[j] * lt3[j]) {
                                printf("%d\n", A + a[i] * lt2[i]);
                                return 0;
                            }
                        }
                }
            a[i] = init.first;
            b[j] = init.second;
            A = INIT.first;
            B = INIT.second;
        }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}