#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
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

const int N = 100002;
const int oo = 1000000007;

template<typename T>
inline void maximize(T &__x, const T &__y) {
    __x = max(__x, __y);
}
template<typename T>
inline void minimize(T &__x, const T &__y) {
    __x = min(__x, __y);
}
string car[N];
int L[N], R[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int ccase; scanf("%d", &ccase);
	car[0] = "UNDETERMINED";
	while (ccase--) {
        int D, Q, money;
        scanf("%d\n", &D);
        FOR(i,1,D) {
            cin >> car[i] >> L[i] >> R[i];
        }
        scanf("%d", &Q);
        FOR(j,1,Q) {
            cin >> money;
            bool done = false;
            int index = 0;
            FOR(i,1,D) if (L[i] <= money && money <= R[i]) {
                if (index != 0) {
                    puts("UNDETERMINED");
                    done = true;
                    break;
                } else
                index = i;
            }
            if (!done) cout << car[index] << endl;
        }
        if (ccase) cout << endl;
//        FOR(i,1,D)
	}
}
