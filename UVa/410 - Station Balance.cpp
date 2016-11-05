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
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;
int a[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int ccase = 0, C, S;
	while (scanf("%d%d", &C, &S) != EOF) {
//        if (ccase) aprintf("\n");
        ++ccase;
        printf("Set #%d\n", ccase);
        double aver = 0, imbal = 0;
        memset(a,0,sizeof a);
        FOR(i,1,S) scanf("%d", &a[i]), aver += a[i];
        aver /= C;
        maximize(S, 2*C);
        sort(a+1, a+1+S);
        FOR(i,1,S/2) {
            printf("%2d:", i-1);
            if (a[i] != 0 || a[S-i+1] != 0) printf(" ");
            if (a[i] != 0) printf("%d", a[i]);
            if (a[i] != 0 && a[S-i+1] != 0) printf(" ");
            if (a[S-i+1] != 0) printf("%d", a[S-i+1]);
            printf("\n");
            imbal += abs(- aver + a[i] + a[S-i+1]);
        }
        printf("IMBALANCE = %.5f\n\n", imbal);
//        printf("\n");
	}
}
