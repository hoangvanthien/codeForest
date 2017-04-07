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

const int N = 205;
const int oo = 1000000007;
int m, n, a[N][N], r[N][N], c[N][N];
bool mark[N];

bool check() {
    f1(i, m) {
        memset(mark, 0, sizeof mark);
        f1(j, n) if (a[i][j]) {
                if (mark[a[i][j]]) return false;
                mark[a[i][j]] = true;
            }
    }

    f1(j, n) {
        memset(mark, 0, sizeof mark);
        f1(i, m) if (a[i][j]) {
                if (mark[a[i][j]]) return false;
                mark[a[i][j]] = true;
            }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("lamps.out", "w", stdout);
#endif // ONLINE_JUDGE
    srand(time(NULL));
    scii(m, n);
    int x, y, d = 0;
    while (~scii(x, y)) a[x][y] = -1;
    f1(i, m) f1(j, n) a[i][j] = rand() % 2 - 1;
    f1(i, m) {
        int cnt = 0;
        f1(j, n) if (a[i][j] == -1) ++cnt;
        maximize(d, cnt);
    }
    f1(j, n) {
        int cnt = 0;
        f1(i, m) if (a[i][j] == -1) ++cnt;
        maximize(d, cnt);
    }
    f1(i, m) f1(j, n) if (a[i][j] == -1) {
                f1(color, d) if (!r[i][color] && !c[j][color]) {
                        r[i][color] = c[j][color] = 1;
                        a[i][j] = color;
                        break;
                    }
                if (a[i][j] == -1) {
                    int A = 0, B = 0;
                    f1(color, d) if (!r[i][color]) {
                            A = color;
                            break;
                        }
                    f1(color, d) if (!c[j][color]) {
                            B = color;
                            break;
                        }
                    int t = j;
                    bool flag;
                    vector<II > v;
                    while (1.0 * clock() / CLOCKS_PER_SEC < 1.0) {
                        flag = false;
                        f1(k, m) if (a[k][t] == A) {
//                                a[k][t] = B;
                                v.pb(mp(k, t));
                                t = k;
                                flag = true;
                                break;
                            }
                        if (!flag) break;
                        flag = 0;
                        f1(k, n) if (a[t][k] == B) {
//                                a[t][k] = A;
                                v.pb(mp(t, k));
                                t = k;
                                flag = true;
                                break;
                            }
                        if (!flag) break;
                    }
                    a[i][j] = A;
                    r[i][A] = c[j][A] = 1;
                    forit(it, v)
                        if (a[it->F][it->S] == A) {
                            r[it->F][A] = c[it->S][A] = 0;
                            r[it->F][B] = c[it->S][B] = 1;
                            a[it->F][it->S] = B;
                        } else {
                            r[it->F][A] = c[it->S][A] = 1;
                            r[it->F][B] = c[it->S][B] = 0;
                            a[it->F][it->S] = A;
                        }
                }
            }
    if (!check()) {
        puts("WRONG");
    }
//    printf("%d\n", d);
//    f1(i, m) f1(j, n) if (a[i][j]) printf("%d %d %d\n", i, j, a[i][j]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}