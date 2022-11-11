#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
vector<int> arr;
int maxLen = -987654321;
int dp[201];

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }

        if(maxLen < dp[i])
            maxLen = dp[i];
    }

    cout << n - maxLen << '\n';


    return 0;
}