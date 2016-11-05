#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define maxN 100002
#define mp make_pair
#define F first
#define S second

pair<char, int> ar[maxN];
string s;
int pos = -1, n;

void init() {
	s = "";
    getline(cin, s);
    if (s.length() == 0) exit(0);
    FOR(i,0,s.length()-1) ar[i] = mp(s[i], i), pos = (s[i] == '@') ? i : pos;
    sort(ar, ar+s.length());
    n = s.length();
}

int main() {
    freopen("bwt.inp", "r", stdin);
    freopen("bwt.out", "w", stdout);
	do {
        init();
        string ans = "";
        int i = 0;
        while (i < n) {
            if (ar[pos].F != '@') ans += ar[pos].F; else break;
            pos = ar[pos].S;
        }
        cout<<ans<<endl;
	} while (1);
}

