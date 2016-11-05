#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
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
int k;
char S[N];
bool digit[10];
vector<int> ans;
int main() {
	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d %s", &k, S);
	int n = strlen(S);
	REP(i, n) digit[S[i] - '0'] = true;
	DFOR(i,9,0) if (digit[i] == false) ans.pb(i);
    if (ans.size() > k || ans.empty()) {
        cout << 0;
        return 0;
    }
    if (digit[0] == false) {
        ans.pop_back();
        ans.back() = 0;
    }
    while (ans.size() < k) ans.pb(ans.back());
    if (ans.back() == 0) {
        int firstdigit = 0;
        FOR(i,1,9) if (digit[i] == false) {
            firstdigit = i;
            break;
        }
        ans.back() = firstdigit;
    }
    if (ans.back() == 0) cout << 0; else
    forrit(it, ans) cout << *it;
}

