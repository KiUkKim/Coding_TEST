#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int n;
int maxN = 0;
vector<int> arr;
int dp[1001];

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n ; i++)
    {
        int tmp;
        cin >> tmp;

        arr.push_back(tmp);
    }

    for(int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i]; 
        }

        if(maxN < dp[i])
        {
            maxN = dp[i];
        }
    }

    cout << dp[0] << '\n';

    cout << maxN << '\n';


    return 0;
}