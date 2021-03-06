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

const int N = 100002;
const int oo = 1000000007;
int n, a[N], cntQuery, ind[N], start[N], cnt[N], T[N * 4];


void initTree(int node, int l, int r) {
    if (l == r) {
        T[node] = cnt[l];
        return;
    }
    int mid = (l + r) / 2;
    initTree(node * 2, l, mid);
    initTree(node * 2 + 1, mid + 1, r);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
}

int getMax(int node, int l, int r, int i, int j) {
    if (i > r || j < l || l > r) return -oo;
    if (i <= l && r <= j) return T[node];
    int mid = (l + r) / 2;
    return max(getMax(node * 2, l, mid, i, j), getMax(node * 2 + 1, mid + 1, r, i, j));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    while (scanf("%d", &n)) {
        if (n == 0) break;
        memset(cnt, 0, sizeof cnt);
        memset(T, 0, sizeof T);
        sci(cntQuery);
        f1(i, n) sci(a[i]);
        a[n + 1] = oo;
        int t = 1;
        ind[1] = 1;
        start[1] = 1;
        FOR(i, 2, n + 1) if (a[i] > a[i - 1]) {
                ind[i] = ++t;
                start[t] = i;
            } else ind[i] = ind[i - 1];
        t--;
        f1(i, n) cnt[ind[i]]++;
        initTree(1, 1, t);
        while (cntQuery--) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (ind[y] == ind[x]) {
                printf("%d\n", y - x + 1);
                continue;
            }
            int temp1 = start[ind[x] + 1] - x, temp2 = y - start[ind[y]] + 1;
            if (ind[y] - 1 == ind[x]) {
                printf("%d\n", max(temp1, temp2));
                continue;
            }
            x = start[ind[x] + 1];
            y = start[ind[y]] - 1;
            int temp3 = getMax(1, 1, t, ind[x], ind[y]);
            printf("%d\n", max(temp1, max(temp2, temp3)));

        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}