#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;

int map[1000][1000];
vector<int> vc;

int main()
{
    fastio;

    cin >> n;

    int EndNum = ( n * (1 + n) ) / 2;

    int cnt = 1;

    // rotate - 1 아래 대각으로, 2 오른쪽으로 , 3, 위 대각으로
    int rotate = 1;
    
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = 0;

    while(cnt <= EndNum)
    {
        if(rotate == 1)
        {
            for(int i = top; i <= bottom; i++)
            {
                map[i][left] = cnt++;
            }

            top++;
            left++;
            rotate = 2;
        }

        else if(rotate == 2)
        {
            for(int i = left; i <= bottom - right; i++)
            {
                map[bottom][i] = cnt++;
            }
            bottom--;
            rotate = 3;
        }

        else if(rotate == 3)
        {
            for(int i = bottom; i >= top; i--)
            {
                map[i][i - right] = cnt++;
            }

            right++;
            top++;
            rotate = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] != 0)
            {
                vc.push_back(map[i][j]);
            }
        }
    }

    for(auto i : vc)
    {
        cout << i << ' ';

    }

    return 0;
}