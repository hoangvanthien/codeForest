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

const int N = 30;
const int oo = 1000000007;
int n, a[N], m, mark[N], mark2[N];
LL k, p[N][N];
char T[N];

bool check() {
    f1(i, m) if (a[i] > n || a[i] <= 0) return false;
    memset(mark2, 0, sizeof mark2);
    f1(i, m) mark2[a[i]]++;
    f1(i, m) if (mark2[a[i]] > 1) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    scni(TT);
    f1(i, 26) {
        p[0][i] = 1;
        f1(j, 26) {
            p[j][i] = (p[j - 1][i] * (i - j + 1)) % 2000000001;
        }
    }
    while (TT--) {
        scanf("%d %d\n", &n, &m);
        scanf("%c %s", &T[0], T + 1);
        k = 0;
        memset(mark, 0, sizeof mark);
        if (T[0] == 'W') {
            if ((int) strlen(T) - 1 <= 10) {
                for (int i = 1; i < strlen(T); ++i) k = (k * 10) + T[i] - '0';
            } else {
                puts("Incorrect data");
                continue;
            }
            if (k > p[m][n]) {
                puts("Incorrect data");
                continue;
            }
            f0(i, N) T[i] = '\0';
            f1(i, m) {
                int cnt = (int) ((k - 1) / p[m - i][n - i] + 1);
                k -= (cnt - 1) * p[m - i][n - i];
                for (int j = 1; j <= n && cnt != 0; ++j) {
                    if (!mark[j]) {
                        --cnt;
                        if (cnt == 0) T[i - 1] = 'a' + (j - 1), mark[j] = 1;
                    }
                }
            }
            if (k == 1) printf("%s\n", T); else puts("Incorrect data");

        } else {
            f1(i, m) a[i] = (T[i] - 'a') + 1;
            if (!check() || strlen(T) != m + 1) {
                puts("Incorrect data");
                continue;
            }
            f1(i, m) {
                mark[a[i]] = 1;
                int cnt = 0;
                f1(j, a[i] - 1) if (!mark[j]) ++cnt;
                k += cnt * p[m - i][n - i];
            }
            printf("%lld\n", k + 1);
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}