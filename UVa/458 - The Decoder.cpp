#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
int main() {
	string s;
	while (getline(cin, s)) {
		FOR(i,0,s.length()-1)
            cout << (char)((int)s[i] - 7);
		cout << endl;
	}
}
