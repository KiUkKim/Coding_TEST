#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int num;
int dp[1000001];

int main()
{
    fastio;

    cin >> num;

    dp[0] = 0;
    dp[2] = 1;
    dp[3] = 1;

    // 2로 나누어질 때와, 3으로 나누어질때를 구별해준다.
    for(int i = 4; i <= num; i++)
    {
        // 해당 dp는 2로 나누어질때와 3으로 나누어질 떄를 구분
        // 두개다 해당되지 않는 경우에는 나머지 수만큼 더해주면 된다.
        // 그래서 이를 비교시키면 되는 문제이다.
        // 따라서 점화식은 dp[n] = min(dp[n/2] + n%2 , dp[n/3] + n% 3)형태이다.
        dp[i] = min(dp[i/2] + 1 + i%2, dp[i/3] + 1 + i % 3);
    }    

    cout << dp[num] << '\n';

    return 0;
}