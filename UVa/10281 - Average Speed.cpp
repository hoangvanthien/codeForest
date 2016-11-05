// RM
#include "bits/stdc++.h"

using namespace std;

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define pb push_back
#define nl puts("")

int conv(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int h, m, s;
    double velo = 0.0, dist = 0;
    vector<int> et;
    et.pb(0);
    while (~scanf("%d:%d:%d", &h, &m, &s)) {
        int t = conv(h, m, s);
        char ch;
        scanf("%c", &ch);
        dist += velo / 3600 * (t - et.back());
        et.pb(t);
        if (ch == '\n') {
            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, dist);
        } else {
            scanf("%lf", &velo);
        }
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}