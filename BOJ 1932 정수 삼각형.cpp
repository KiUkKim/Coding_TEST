#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int num;
int tri[501][501];
int dp[501][501];

// 해당 문제의 접근 아이디어는 왼쪽 대각선 아래와 오른쪽 대각선 아래로 내려온다는 점을 이용하였다.
// 삼각형의 그림을 보면 해당 행의 제일 왼쪽, 제일 오른쪽은 비교군이 없기 때문에, 위의 합에 더해주는 형식이다.
// 그러면 중간에 껴 있는 숫자들은, 이전 위의 dp의 오른쪽 대각선과 이전 위 오른쪽 dp의 왼쪽 대각선이 될 수 있는 경우이므로 이를 따져주면된다.

int main()
{
    fastio;

    cin >> num;

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            cin >> tri[i][j];
        }
    }

    // 첫번째 행과 두번째 행은 무조건 다음과 같이 이루어진다.
    dp[0][0] = tri[0][0];

    dp[1][0] = dp[0][0] + tri[1][0];
    
    dp[1][1] = dp[0][0] + tri[1][1];

    for(int i = 2; i < num; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + tri[i][j];
            }
            
            else if(j == i) 
            {
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }

            else{
                dp[i][j] = max(dp[i-1][j-1] + tri[i][j], dp[i-1][j] + tri[i][j]);
            }
        }
    }

    int maxN = -123456789;

    for(int i = 0; i < num; i++)
    {
        maxN = max(maxN, dp[num-1][i]);
    }

    cout << maxN << '\n';
    

    return 0;
}