#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[1002], n;

int main()
{
    fastio;

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }


    cout << dp[n] << '\n';

    return 0;
}