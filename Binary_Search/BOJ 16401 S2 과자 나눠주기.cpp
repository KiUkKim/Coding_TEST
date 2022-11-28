#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int cusion, snack;
vector<int> snackLen;

int main()
{
    fastio;

    int maxN = -987654321;

    cin >> cusion >> snack;

    for(int i = 0; i< snack; i ++)
    {
        int tmp;
        cin >> tmp;

        snackLen.push_back(tmp);
        
        maxN = max(maxN, tmp);
    }

    sort(snackLen.begin(), snackLen.end());

    int left = 1;
    int right = maxN;
    int mid = (left + right) / 2;
    int ans = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        int cnt = 0;

        for(int i = 0; i < snackLen.size(); i++)
        {
            cnt += snackLen[i] / mid;
        }

        // 적게 나눠줬거나 알맞게 나눠준 경우
        if(cnt >= cusion)
        {
            left = mid + 1;
            ans = mid;
        }

        // 너무 많이 나눠준 경우
        else if(cnt < cusion)
        {
            right = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}