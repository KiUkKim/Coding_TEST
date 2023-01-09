#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int cnt;

int main()
{
    fastio;
    
    int answer = 0;

    int n;

    cin >> n;

    int idx = 1;

    while(idx <= n)
    {
        int sum = 0;
        for(int i = idx; i <= n; i++)
        {
            sum += i;

            if(sum == n)
            {
                cnt++;
                idx++;
                break;
            }

            else if(sum > n)
            {
                idx++;
                break;
            }
        }
    }

    answer = cnt;

    cout << answer << '\n';

    return 0;
}

