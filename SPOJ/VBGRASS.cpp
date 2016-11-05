#include <bits/stdc++.h>

using namespace std;

#define MaxN 101

int ar[MaxN][MaxN];
bool tt[MaxN][MaxN];
int Max,Count,m,n,_count;

void init()
{
	freopen("VBGRASS.INP", "r", stdin);
	freopen("VBGRASS.OUT", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i)
		for (int j=-1; j<n; ++j)
		{
			char c;
			scanf("%c",&c);
            if (c=='.')
            {
                ar[i][j] = 1;
                tt[i][j]=true;
            }
            if (c == '#')
            {
                ar[i][j] = 0;
                tt[i][j] = false;
            }
		}
	Max = 0;
	Count = 0;
}

void print()
{
    printf("%d", Count);
}

void loang(int i, int j)
{
    if (!(0<=i && i<m && 0<=j && j<n)) return;
    if (tt[i][j] == true) return;
    tt[i][j] = true;
    loang(i+1,j);
    loang(i,j+1);
    loang(i-1,j);
    loang(i,j-1);
}

int main()
{
    init();
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        if (tt[i][j] == false)
    {
        Count++;
        loang(i,j);
        /*for (int ii=0; ii<m; ++ii)
        {
            for (int jj=0; jj<n; ++jj)
                printf("%d ", (int)tt[ii][jj]);
            printf("\n");
        }
        system("pause");*/
    }
    print();
}
