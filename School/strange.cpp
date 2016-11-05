// STRANGE.CPP
// RM
#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
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
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1
#ifdef ONLINE_JUDGE
#define printLL(x) printf("%I64d", x)
#else
#define printLL(x) cout << x
#endif

const int N = 200005;
const int oo = 1000000007;
string s, temp;
set<string> seq, str;
int maxLength[250];
vector<pair<char, int> > v;
set<string> strange;

bool check(string _s) {
    seq.clear();
    str.clear();
    for (int i = 0; i < (1 << _s.size()); ++i) {
        temp = "";
        for (int j = 0; j < _s.size(); ++j)
            if (i & (1 << j)) {
                temp += _s[j];
            }
        if (temp != "") seq.insert(temp);
    }
    for (int i = 0; i < _s.size(); ++i) {
        for (int j = i; j < _s.size(); ++j) {
            temp = "";
            for (int t = i; t <= j; ++t) temp += _s[t];
            str.insert(temp);
        }
    }
//    forit(it, seq) cout << *it << " ";
//    nl;
//    nl;
//    forit(it, str) cout << *it << " ";
    if (seq == str) {
        strange.insert(_s);
        return true;
    }
    return false;
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("strange.inp", "r", stdin);
   freopen("strange.out", "w", stdout);
#endif // ONLINE_JUDGE
   getline(cin, s);
   n = (int) s.size();
    // srand(time(NULL));
    // n = 200000;
    // f0(i, n) s += 'a' + rand() % 26;
//    db(s);
    f0(i, n) {
        if (i - 1 >= 0 && s[i] == s[i - 1]) v.back().S++;
        else v.pb(mp(s[i], 1));
    }
    f0(i, v.size()) maximize(maxLength[v[i].F - 'a'], v[i].S);
    vector<LL> v3;
    vector<pair<II, char> > v2;
    int c[26];
    LL ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        v2.clear();
        v3.clear();
        memset(c, 0, sizeof c);
        f0(i, (int) v.size() - 1) if (v[i].F == ch) {
                v2.pb(mp(mp(v[i].S, v[i + 1].S), v[i + 1].F));
            }
        sort(v2.begin(), v2.end());

        forrit(it, v2) {
            char _ch = it->S;
            int x = (it->F).F, y = (it->F).S, pos = _ch - 'a';
            maximize(c[pos], y);
            int sum = 0;
            f0(i, 26) sum += c[i];
            v3.pb(sum);
        }
        reverse(v3.begin(), v3.end());

        for (int len = 1; len <= maxLength[ch - 'a']; ++len) {
            ++ans;
            int pos = upper_bound(v2.begin(), v2.end(), mp(mp(len, 0), '$')) - v2.begin();
            if (pos == v2.size()) continue;
            ans += v3[pos];
        }

    }
    cout << ans << endl;
//    ans = 0;
//    f0(i, s.size()) FOR(j, i, (int) s.size() - 1) {
//            check(s.substr(i, j - i + 1));
//        }
//    db(strange.size());
//    forit(it, strange) db(*it);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}