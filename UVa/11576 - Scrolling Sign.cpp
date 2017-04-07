#include "bits/stdc++.h"

using namespace std;

const int N = 10005;
char T[N], s[N];
int b[N];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int n, w;
        scanf("%d%d", &n, &w);
        scanf("%s", T);
        for (int _ = 2; _ <= w; ++_) {
            scanf("%s", s);
            memset(b, 0, sizeof b);
            b[0] = -1;
            for (int i = 0, j = -1; i < n;) {
                while (j >= 0 && s[i] != s[j]) j = b[j];
                ++i, ++j;
                b[i] = j;
            }
            for (int i = 0, j = 0; i < strlen(T);) {
                while (j >= 0 && T[i] != s[j]) j = b[j];
                ++i, ++j;
                if (i == strlen(T)) strcat(T, s + j);
            }
        }
        printf("%d\n", (int) strlen(T));
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}