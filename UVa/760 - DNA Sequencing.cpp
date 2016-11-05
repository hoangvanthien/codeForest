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


const int N = 605;
const int oo = 1000000007;

int n,a,b,c[N],tempSA[N],SA[N],tempRA[N],RA[N],Phi[N],LCP[N],PLCP[N];
string s,S1,S2;

void countingSort(int k) {
    int sum = 0;
    memset(c, 0, sizeof c);
    int imax = max(300, n);
    REP(i,n) if (i + k < n) c[RA[i+k]]++; else c[0]++;
    REP(i,imax) {
        int temp = c[i];
        c[i] = sum;
        sum += temp;
    }
    REP(i,n) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
//    if (SA[i] + k < n) tempSA[c[RA[SA[i]+k]]++] = SA[i]; else tempSA[c[0]++] = SA[i];
    REP(i,n) SA[i] = tempSA[i];
}

void constructSA() {
    int r;
    REP(i,n) RA[i] = s[i];
    REP(i,n) SA[i] = i;
    for(int k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        FOR(i,1,n-1) if (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) tempRA[SA[i]] = r;
        else tempRA[SA[i]] = ++r;
        REP(i,n) RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

void constructLCP() {
    Phi[SA[0]] = -1;
    FOR(i,1,n-1) Phi[SA[i]] = SA[i-1];
    int L = 0;
    REP(i,n) {
        if (Phi[i] == -1) {PLCP[i] = 0; continue; }
        while (s[i+L] == s[Phi[i]+L]) ++L;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    REP(i,n) LCP[i] = PLCP[SA[i]];
}
int owner(int index) {return index < a ? 1 : 2;}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	int cnt = 0;
    while ((cin >> S1) && (cin >> S2)) {
        ++cnt;
        if (cnt > 1) cout << endl;
        S1+= '$'; S2+= '#';
        a = S1.size();
        b = S2.size();
        s = S1+S2;
        n = s.size();
        constructSA();

        constructLCP();
//        cout << *max_element(LCP, LCP+n) << endl;
//        FOR(i,0,n-1) {
//            FOR(j,SA[i],s.size()-1) cout << s[j];
//            cout << " " << LCP[i] << endl;
//        }
        int mmax = 0;
        FOR(i,1,n-1) {
            if (owner(SA[i]) != owner(SA[i-1])) {
                mmax = max(mmax, LCP[i]);
            }
        }
        if (mmax == 0) {
            cout << "No common sequence." << endl;
            continue;
        }
        string prev;
        FOR(i,1,n-1) {
            if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] == mmax) {
                string temp = "";
                FOR(j,SA[i],SA[i] + mmax-1)
                    temp+= s[j];
                if (temp != prev) {
                    cout << temp << endl;
                    prev = temp;
                }
            }
        }

    }
}
