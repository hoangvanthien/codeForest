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

stringstream ss;
list<string> ls;
int num;
bool isNum, isWord;

void finishNum() {
	list<string>::iterator it = ls.end();
	while (num--) --it;
	cout << *(it);
	ls.pb(*(it));
	ls.erase(it);
	num = 0;
	isNum = 0;
}

void finishWord() {
	ls.pb(ss.str());
	ss.str("");
	isWord = false;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	string s;
	while (getline(cin, s) && s != "0") {
		FOR(i,0,(int)s.size()-1) {
			if (isalpha(s[i])) {
				ss << s[i];
				cout << s[i];
				isWord = true;
			} else
				if (isalnum(s[i])) {
					num = num*10 + (s[i] - '0');
					isNum = true;
				} else {
					if (isNum) finishNum();
					if (isWord) finishWord();
					cout << s[i];
				}
		}
		if (isNum) finishNum();
        if (isWord) finishWord();
		cout << endl;
	}
}
