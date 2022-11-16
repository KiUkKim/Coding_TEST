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
vector<int> arr;
int dp[1001];
int ans[1001];

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        dp[i] = 1;
        ans[i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j] && dp[i] + ans[j] > ans[j])
            {
                ans[j] = max(ans[j], ans[i] + dp[j]);
            }
        }
    }

    int maxN = -123456789;
    for(int i = 0; i < n; i++)
    {
        maxN = max(maxN, ans[i]);
    }

    cout << maxN << '\n';

    return 0;
}