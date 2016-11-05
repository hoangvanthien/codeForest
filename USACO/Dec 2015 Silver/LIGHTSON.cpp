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

const int N = 102;
const int oo = 1000000007;
vector<II > ar[N][N];
int n, m;

struct node {
    bool visited, reachable, lit;

    node() {
        visited = 0;
        reachable = 0;
        lit = 0;
    }

    node(bool v, bool r, bool l) {
        visited = v;
        reachable = r;
        lit = l;
    }
};

node room[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d%d", &n, &m);
    f1(i, m) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ar[a][b].pb(mp(c, d));
    }
    room[1][1] = node(1, 1, 1);
    room[1][2] = room[2][1] = node(0, 1, 0);
    queue<II > q;
    q.push(mp(1, 1));
    while (q.size()) {
        II p = q.front();
        q.pop();
        int x = p.F, y = p.S;
        forit(it, ar[x][y]) {
            int u = it->first, v = it->second;

            if (!room[u][v].visited && !room[u][v].lit && room[u][v].reachable) {
                room[u][v] = node(1, 1, 1);
                q.push(mp(u, v));
            }
            room[u][v].lit = 1;
        }
        REP(i, 4) {
            int u = x + dx[i], v = y + dy[i];
            if (!room[u][v].visited && room[u][v].lit && !room[u][v].reachable) {
                room[u][v] = node(1, 1, 1);
                q.push(mp(u, v));
            }
            room[u][v].reachable = 1;
        }
    }
    int ans = 0;
    f1(i, n) f1(j, n) if (room[i][j].lit) ++ans;
    cout << ans;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}