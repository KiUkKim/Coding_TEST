#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;


char star[3072][6144];

void Rectangle(int x, int y, int n)
{
    if(n==3)
    {
        // 꼭지점
        star[x][y] = '*';
        
        // 두번째 별
        star[x+1][y-1] = '*';
        star[x+1][y+1] = '*';
        
        // 마지막 별
        for(int j = y-2; j <= y+2; j++)
        {
            star[x+2][j] = '*';
        }
        return;
    }

    Rectangle(x, y, n / 2);
    Rectangle(x+n / 2, y - n / 2, n / 2);
    Rectangle(x+n / 2, y + n / 2, n / 2);

}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 * n; j++)
        {
            star[i][j] = ' ';
        }
    }

    Rectangle(0, n - 1, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2*n; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}