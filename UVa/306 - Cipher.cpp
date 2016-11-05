#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define N 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound


II a[N];
int n,k;
int cycle[N];
bool tt[N];
string s;


int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	while (scanf("%d", &n) && n != 0) {
        FOR(i,1,n) scanf("%d", &a[i].F), a[i].S = i;
        FOR(j,1,n) {
            int cnt = 1;
            memset(tt, 0, sizeof tt);
            tt[j] = true;
            for(int i = a[j].F; tt[i] == false; i = a[i].F) ++cnt;
            cycle[j] = cnt;
        }
        //sort(a+1, a+1+n);
        while (scanf("%d", &k) && k != 0) {
            char ch; scanf("%c", &ch);
            getline(cin, s);
//            vector<string> ar;
    //        db(s);
            while (s.size() < n) s += ' ';
            string temp = s;
            FOR(i,1,n) {
                int cnt = cycle[i], t = k%cnt;
                int j = i;
                while (t > 0) {
                    j = a[j].F;
                    --t;
                }
                temp[j-1] = s[i-1];
//                FOR(i,1,t) {
//                    string temp = s;
//                    FOR(i,1,n) temp[i-1] = s[a[i].S-1];
//                    FOR(i,0,n-1) s[i] = temp[i];
    //                int pos = find(ar.begin(), ar.end(), s) - ar.begin();
    //                if (pos == ar.size()) ar.pb(s); else {
    //                    int t = k % (ar.size() - pos);
    //                    if (t == 0) cout << ar.back() << endl; else
    //                        cout << ar[pos+t-1] << endl;
    //                    break;
    //                }
//                }
            }
            cout << temp << endl;
        }
        cout << endl;
	}
}
