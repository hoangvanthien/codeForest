#include <bits/stdc++.h>

using namespace std;
#define FOR(i,x,y) for(int i = x; i < y; ++i)
#define DFOR(i,x,y) for(int i = x; i > y; --i)
#define II pair<int, int>
#define mp make_pair
#define F first
#define S second

II couple[12] = {
	mp(2,4),
	mp(1,3), mp(2,3), mp(3,4), mp(3,5),
	mp(1,2), mp(4,5),
	mp(0,2), mp(0,1), mp(0,5), mp(0,4),
	mp(1,5)
};
int sum[6], answer[12], freecell[6];
bool tt[13];

int CharToInt(char c)
{
	return (int)c - 64;
}

char IntToChar(int i)
{
	return (i+64);
}

inline void push(int value, int _index)
{
    int _first = couple[_index].F;
    int _second = couple[_index].S;
    sum[_first] -= value;
    sum[_second] -= value;
    freecell[_first] --;
    freecell[_second] --;
    tt[value] = true;
    answer[_index] = value;
}

inline void pop(int value, int _index)
{
    int _first = couple[_index].F;
    int _second = couple[_index].S;
    sum[_first] += value;
    sum[_second] += value;
    freecell[_first] ++;
    freecell[_second] ++;
    tt[value] = false;
    answer[_index] = 0;
}

void init()
{
	#ifndef ONLINE_JUDGE
		freopen("LSTAR.INP", "r", stdin);
	#endif // ONLINE_JUDGE

	int index = -1;
    fill_n(sum, 6, 26);
    fill_n(freecell, 6, 4);
	FOR(i,0,5)
	{
		FOR(j,0,11)
		{
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n' || tmp == '.') continue;
			index ++;
			if (tmp == 'x') continue;
			int val = CharToInt(tmp);
            push(val, index);
		}
	}
}

void print()
{
    printf("....%c....\n", IntToChar(answer[0]));
    printf(".");
    FOR(i,1,5) printf("%c.", IntToChar(answer[i]));
    printf("\n..%c...%c..\n", IntToChar(answer[5]), IntToChar(answer[6]));
    printf(".");
    FOR(i,7,11) printf("%c.", IntToChar(answer[i]));
    printf("\n....%c....", IntToChar(answer[11]));
    //exit(0);
}

void attemp(int i)
{
    //print();
    if (answer[i] != 0)
    {
        attemp(i+1);
        return;
    }
    if (i==12) // 0..11 have passed
    {
        FOR(j,0,6)
        if (sum[j] != 0) return;

        print();
        exit(0);
    }
    int _f = couple[i].F;
    int _s = couple[i].S;
    int left = max(sum[_f]-12*freecell[_f], max(sum[_s]-12*freecell[_s], 1));
    int right = min(sum[_f]-freecell[_f], min(sum[_s]-freecell[_s], 12));
    if (left > right) return;

    if (freecell[_f] == 1)
    {
        left = sum[_f];
        right = sum[_f];
    }
    if (freecell[_s] == 1)
    {
        left = sum[_s];
        right = sum[_s];
    }

    FOR(j,left,right+1)
    if (tt[j] == false)
    {
        push(j, i);
        if (sum[_f] >= 0 && sum[_s] >=0)
        {
            attemp(i+1);
        }
        pop(j, i);
    }
}

int main()
{
	init();
	FOR(i,0,12)
	if (answer[i] == 0)
    {
        attemp(i);
        break;
    }
}
