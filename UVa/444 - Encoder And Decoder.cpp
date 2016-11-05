#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
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
#define SSTR( x ) dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string strrev(string a) {
	FOR(i,0,a.length()/2 - 1) {
		swap(a[i], a[a.length()-i-1]);
	}
	return a;
}

int val(char c) {
	return c - '0';
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	string s;
	while (getline(cin, s)) {
        if (s.length() == 0) {
            cout << endl;
            continue;
        }
		if ('0' <= s[0] && s[0] <= '9') {
			for(int i = s.length()-1; i >= 0; i -= 2) {
				int temp = val(s[i])*10 + val(s[i-1]);
				if (s[i] == '1') {
                    temp = temp*10 + val(s[i-2]);
                    --i;
				}
				cout << (char) temp;
			}
		} else {
			DFOR(i,s.length()-1,0) {
				string temp = toString((int)s[i]);
				//db(temp);
				temp = strrev(temp);
				cout << temp;
			}
		}
		cout << endl;
	}
}
